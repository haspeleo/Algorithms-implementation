/** @file   imageutils.cpp
    @author Philip Abbet (philip.abbet@idiap.ch)

    Implementation of the 'ImageUtils' class
*/

#include "imageutils.h"
#include <FreeImage.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;
using namespace Mash;


/****************************** STATIC ATTRIBUTES *****************************/

bool                ImageUtils::bInitialised = false;
IImageDownloader*   ImageUtils::pDownloader  = 0;


/******************************* STATIC METHODS *******************************/
 
Image* createImageFromBitmap(FIBITMAP* pBitmap)
{
    // Assertions
    assert(pBitmap);
    
    // Convert the image if necessary
    FIBITMAP* pConverted = 0;
    switch (FreeImage_GetImageType(pBitmap))
    {
        case FIT_RGB16:
            pConverted = FreeImage_ConvertTo24Bits(pBitmap);
            break;

        case FIT_RGBA16:
            pConverted = FreeImage_ConvertTo32Bits(pBitmap);
            break;

        case FIT_BITMAP:
            if (FreeImage_GetBPP(pBitmap) == 16)
                pConverted = FreeImage_ConvertTo24Bits(pBitmap);
            break;
		
		default:
			break;
    }

    if (pConverted)
    {
        FreeImage_Unload(pBitmap);
        pBitmap = pConverted;
    }

    // Retrieve infos about the image
    unsigned int width  = FreeImage_GetWidth(pBitmap);
    unsigned int height = FreeImage_GetHeight(pBitmap);
    unsigned int bpp    = FreeImage_GetBPP(pBitmap);
    unsigned int pitch  = FreeImage_GetPitch(pBitmap);

    if ((FreeImage_GetImageType(pBitmap) != FIT_BITMAP) || ((bpp != 8) && (bpp != 24) && (bpp != 32)))
    {
        FreeImage_Unload(pBitmap);
        return 0;
    }
        
    // Create an image object containing the image
    Image* pImage = new Image(width, height);

    switch (bpp)
    {
        case 8:
            {
                pImage->addPixelFormats(Image::PIXELFORMAT_RGB);

                byte_t*     pSrc    = FreeImage_GetBits(pBitmap);
                RGBPixel_t* pDst    = pImage->rgbBuffer() + (height - 1) * width;
                RGBQUAD*    palette = FreeImage_GetPalette(pBitmap);
                for (unsigned int y = 0; y < height; ++y)
                {
                    byte_t* srcPixel = pSrc;
                    RGBPixel_t* dstPixel = pDst;
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        dstPixel->r = palette[*pSrc].rgbRed;
                        dstPixel->g = palette[*pSrc].rgbGreen;
                        dstPixel->b = palette[*pSrc].rgbBlue;
            
                        ++srcPixel;
						++dstPixel;
                    }
        
                    pSrc += pitch;
                    pDst -= width;
                }
                
                ImageUtils::convertImageToPixelFormats(pImage, Image::PIXELFORMAT_GRAY);
            }
            break;

        case 24:
        case 32:
            {
                pImage->addPixelFormats(Image::PIXELFORMAT_RGB);

                byte_t* pSrc = FreeImage_GetBits(pBitmap);
                RGBPixel_t* pDst = pImage->rgbBuffer() + (height - 1) * width;
                for (unsigned int y = 0; y < height; ++y)
                {
                    byte_t* srcPixel = pSrc;
                    RGBPixel_t* dstPixel = pDst;
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        dstPixel->r = srcPixel[FI_RGBA_RED];
                        dstPixel->g = srcPixel[FI_RGBA_GREEN];
                        dstPixel->b = srcPixel[FI_RGBA_BLUE];
            
                        srcPixel += (bpp >> 3);
						++dstPixel;
                    }
        
                    pSrc += pitch;
                    pDst -= width;
                }
            }
            break;

        default:
            assert(false);
            break;
    }
    
    // Cleanup
    FreeImage_Unload(pBitmap);

    return pImage;
}


/*********************************** METHODS **********************************/

Image* ImageUtils::loadImage(const std::string& strUrl)
{
    // Assertions
    assert(!strUrl.empty());

    // Initialise FreeImage if necessary
    if (!ImageUtils::bInitialised)
    {
        FreeImage_Initialise(true);
        ImageUtils::bInitialised = true;
    }
        
    // Deduce the file format from the filename
    FREE_IMAGE_FORMAT format = FreeImage_GetFIFFromFilename(strUrl.c_str());
    
    // Check that we know how to load the file
    if ((format == FIF_UNKNOWN) || !FreeImage_FIFSupportsReading(format))
        return 0;


    FIBITMAP* pBitmap = 0;
    
    // Local file: load it
    if (strUrl.find("://") == string::npos)
    {
        pBitmap = FreeImage_Load(format, strUrl.c_str(), 0);
    }

    // URL: download it
    else if (pDownloader)
    {
        pBitmap = (FIBITMAP*) pDownloader->loadImage(strUrl);
    }

    // URL: can't handle it
    else
    {
        return 0;
    }

    if (!pBitmap)
        return 0;
        
    return createImageFromBitmap(pBitmap);
}


Image* ImageUtils::createImage(const std::string& strMimeType,
                               unsigned char* pBuffer, long size)
{
    // Assertions
    assert(!strMimeType.empty());
    assert(pBuffer);
    assert(size > 0);

    // MASH Image Format?
    if (strMimeType == "image/mif")
    {
        if (strncmp("MIF", (const char*) pBuffer, 3) != 0)
            return 0;

        unsigned char version = pBuffer[3];
        if (version != 1)
            return 0;

        unsigned int width = pBuffer[4] + pBuffer[5] * 256;
        unsigned int height = pBuffer[6] + pBuffer[7] * 256;
        
        unsigned int nbBytes = 3 * width * height;
        if (nbBytes + 8 != size)
            return 0;

        Image* pImage = new Image(width, height);
        pImage->addPixelFormats(Image::PIXELFORMAT_RGB);
        
        memcpy(pImage->rgbBuffer(), pBuffer + 8, nbBytes);
        
        return pImage;
    }


    // Initialise FreeImage if necessary
    if (!ImageUtils::bInitialised)
    {
        FreeImage_Initialise(true);
        ImageUtils::bInitialised = true;
    }
        
    // Retrieve the file format from the MIME type
    FREE_IMAGE_FORMAT format = FreeImage_GetFIFFromMime(strMimeType.c_str());
    
    // Check that we know how to load the file
    if ((format == FIF_UNKNOWN) || !FreeImage_FIFSupportsReading(format))
        return 0;

    // Load the image from the memory
    FIMEMORY* pMemory = FreeImage_OpenMemory(pBuffer, size);
    if (!pMemory)
        return 0;
    
    FIBITMAP* pBitmap = FreeImage_LoadFromMemory(format, pMemory, 0);
    
    FreeImage_CloseMemory(pMemory);
    
    if (!pBitmap)
        return 0;
        
    return createImageFromBitmap(pBitmap);
}


bool ImageUtils::convertImageToPixelFormats(Image* pImage,
                                            unsigned int pixelFormats)
{
    // Assertions
    assert(pImage);

    // PIXELFORMAT_GRAY
    if ((pixelFormats & Image::PIXELFORMAT_GRAY) &&
        !pImage->hasPixelFormat(Image::PIXELFORMAT_GRAY))
    {
        if (pImage->hasPixelFormat(Image::PIXELFORMAT_RGB))
        {
            pImage->addPixelFormats(Image::PIXELFORMAT_GRAY);

            RGBPixel_t* pSrc = pImage->rgbBuffer();
            byte_t*     pDst = pImage->grayBuffer();
            for (unsigned int i = 0; i < pImage->width() * pImage->height(); ++i)
            {
				*pDst = (byte_t) (((int) pSrc->r * 11 + ((int) pSrc->g << 4) + (int) pSrc->b * 5) >> 5);

				++pSrc;
				++pDst;
            }
        }
    }

    // PIXELFORMAT_RGB
    if ((pixelFormats & Image::PIXELFORMAT_RGB) &&
        !pImage->hasPixelFormat(Image::PIXELFORMAT_RGB))
    {
        if (pImage->hasPixelFormat(Image::PIXELFORMAT_GRAY))
        {
            pImage->addPixelFormats(Image::PIXELFORMAT_RGB);

            byte_t*     pSrc = pImage->grayBuffer();
            RGBPixel_t* pDst = pImage->rgbBuffer();
            for (unsigned int i = 0; i < pImage->width() * pImage->height(); ++i)
            {
                pDst->r = *pSrc;
                pDst->g = *pSrc;
                pDst->b = *pSrc;

				++pSrc;
				++pDst;
            }
        }
    }

    return (pImage->pixelFormats() & pixelFormats) == pixelFormats;
}


Image* ImageUtils::scale(Image* pImage, float scale)
{
    // Assertions
    assert(pImage);
    assert(scale > 0.0f);

    unsigned int width = (unsigned int) (pImage->width() * scale);
    unsigned int height = (unsigned int) (pImage->height() * scale);
    RGBPixel_t paddingColor = { 0 };
    
    return ImageUtils::scale(pImage, width, height, paddingColor);
}


Image* ImageUtils::scale(Image* pImage, unsigned int width, unsigned int height,
                         RGBPixel_t paddingColor)
{
    // Assertions
    assert(pImage);
    assert(width > 0);
    assert(height > 0);


    // Special case: Grayscale images are converted to RGB ones before being scaled
    if (!pImage->hasPixelFormat(Image::PIXELFORMAT_RGB) && pImage->hasPixelFormat(Image::PIXELFORMAT_GRAY))
    {
        Image* pRGBImage = new Image(pImage->width(), pImage->height());
        pRGBImage->addPixelFormats(Image::PIXELFORMAT_RGB);

        byte_t* pSrc = pImage->grayBuffer();
        RGBPixel_t* pDst = pRGBImage->rgbBuffer();
        memset(pDst, 0, pRGBImage->width() * pRGBImage->height());
        
        for (unsigned int i = 0; i < pImage->width() * pImage->height(); ++i)
        {
            pDst->r = *pSrc;
            pDst->g = *pSrc;
            pDst->b = *pSrc;

			++pSrc;
			++pDst;
        }

        Image* pScaledRGBImage = ImageUtils::scale(pRGBImage, width, height, paddingColor);

        Image* pScaledImage = new Image(width, height);
        pScaledImage->addPixelFormats(Image::PIXELFORMAT_GRAY);

        RGBPixel_t* pSrc2 = pScaledRGBImage->rgbBuffer();
        byte_t* pDst2 = pScaledImage->grayBuffer();
        for (unsigned int i = 0; i < width * height; ++i)
        {
            *pDst2 = pSrc2->r;

			++pSrc2;
			++pDst2;
        }

        delete pScaledRGBImage;
        delete pRGBImage;
        
        return pScaledImage;
    }


    if (!pImage->hasPixelFormat(Image::PIXELFORMAT_RGB))
        return 0;

    FIBITMAP* pBitmap = FreeImage_ConvertFromRawBits((BYTE*) pImage->rgbBuffer(), pImage->width(),
                    pImage->height(), pImage->width() * 3, 24, 0x0000FF, 0x00FF00, 0xFF0000, TRUE);
    

    unsigned int dstWidth, dstHeight;

    float scaleX = (float) width / pImage->width();
    float scaleY = (float) height / pImage->height();

    if (scaleX <= scaleY)
    {
        dstWidth = width;
        dstHeight = (unsigned int) (pImage->height() * scaleX);
    }
    else
    {
        dstHeight = height;
        dstWidth = (unsigned int) (pImage->width() * scaleY);
    }

    FIBITMAP* pScaledBitmap = FreeImage_Rescale(pBitmap, dstWidth, dstHeight, FILTER_CATMULLROM);

    // Create an image object containing the scaled image
    Image* pScaledImage = new Image(width, height);
    pScaledImage->addPixelFormats(Image::PIXELFORMAT_RGB);

    if ((dstWidth != width) || (dstHeight != height))
    {
        RGBPixel_t* pDst = pScaledImage->rgbBuffer();
        for (unsigned int i = 0; i < width; ++i)
        {
            *pDst = paddingColor;
			++pDst;
        }

        for (unsigned int i = 1; i < height; ++i)
        {
            memcpy(pDst, pScaledImage->rgbBuffer(), width * 3);
			pDst += width;
        }
        
        if (height > dstHeight)
        {
            unsigned int offset = (height - dstHeight) >> 1;
            FreeImage_ConvertToRawBits((BYTE*) (pScaledImage->rgbBuffer() + offset * width), pScaledBitmap,
                                       width * 3, 24, 0x0000FF, 0x00FF00, 0xFF0000, TRUE);
        }
        else
        {
            unsigned int offset = ((width - dstWidth) >> 1);
            FreeImage_ConvertToRawBits((BYTE*) (pScaledImage->rgbBuffer() + offset), pScaledBitmap,
                                       width * 3, 24, 0x0000FF, 0x00FF00, 0xFF0000, TRUE);
        }
    }
    else
    {
        FreeImage_ConvertToRawBits((BYTE*) pScaledImage->rgbBuffer(), pScaledBitmap,
                                   width * 3, 24, 0x0000FF, 0x00FF00, 0xFF0000, TRUE);
    }
                           
    // Cleanup
    FreeImage_Unload(pBitmap);
    FreeImage_Unload(pScaledBitmap);
    
    // Convert to other pixel formats if necessary
    if (pImage->hasPixelFormat(Image::PIXELFORMAT_GRAY))
        ImageUtils::convertImageToPixelFormats(pScaledImage, Image::PIXELFORMAT_GRAY);
        
    return pScaledImage;
}


void ImageUtils::setDownloader(IImageDownloader* pDownloader)
{
    ImageUtils::pDownloader = pDownloader;
}

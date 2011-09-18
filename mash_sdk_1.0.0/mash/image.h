/** @file   image.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Declaration of the 'Image' class
*/

#ifndef _MASH_IMAGE_H_
#define _MASH_IMAGE_H_

#include <mash-utils/declarations.h>


namespace Mash
{
    //--------------------------------------------------------------------------
    /// @brief  Represents a byte
    //--------------------------------------------------------------------------
    typedef unsigned char byte_t;
    
    
    //--------------------------------------------------------------------------
    /// @brief  Represents a RGB pixel 
    //--------------------------------------------------------------------------
    struct RGBPixel_t
    {
        byte_t r;
        byte_t g;
        byte_t b;
    };
    
    
    //--------------------------------------------------------------------------
    /// @brief  Represents an image
    ///
    /// The pixel values of the image can be contained in several formats by
    /// this class at the same time. 
    //--------------------------------------------------------------------------
    class MASH_SYMBOL Image
    {
        //_____ Internal types __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Possible pixel formats for the images
        //----------------------------------------------------------------------
        enum tPixelFormat
        {
            PIXELFORMAT_RGB     = 1,     ///< RGB (24 bits) image
            PIXELFORMAT_GRAY    = 2,     ///< Grayscale image, 8 bits

            PIXELFORMAT_ALL = PIXELFORMAT_RGB | PIXELFORMAT_GRAY,
        };


        //_____ Construction / Destruction __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Constructor
        ///
        /// @param  width   Width of the image, in pixels
        /// @param  height  Height of the image, in pixels
        /// @param  view    Index of the view
        //----------------------------------------------------------------------
        Image(unsigned int width, unsigned int height, unsigned int view = 0);

        //----------------------------------------------------------------------
        /// @brief  Destructor
        //----------------------------------------------------------------------
        ~Image();
    

        //_____ Methods __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Returns a copy of the image
        //----------------------------------------------------------------------
        Image* copy() const;

        //----------------------------------------------------------------------
        /// @brief  Add one (or more) pixel format(s) to the image
        ///
        /// @param  pixelFormats    A combination of pixel formats (see
        ///                         tPixelFormat), for instance
        ///                         PIXELFORMAT_RGB | PIXELFORMAT_GRAY
        ///
        /// @remark This has the effect of allocating the needed memory space.
        /// @remark It is safe to add a pixel format more than one time, any
        ///         subsequent call will have no effect
        //----------------------------------------------------------------------
        void addPixelFormats(unsigned int pixelFormats);

        //----------------------------------------------------------------------
        /// @brief  Returns the pixel formats of the image
        //----------------------------------------------------------------------
        inline unsigned int pixelFormats() const
        {
            return _pixelFormats;
        }

        //----------------------------------------------------------------------
        /// @brief  Indicates if the image is represented in a specific pixel
        ///         format 
        ///
        /// @param  pixelFormat     The format
        /// @return                 'true' if the pixels are stored in that
        ///                         format
        //----------------------------------------------------------------------
        inline bool hasPixelFormat(tPixelFormat pixelFormat) const
        {
            return (_pixelFormats & pixelFormat) != 0;
        }
    
        //----------------------------------------------------------------------
        /// @brief  Returns the width of the image, in pixels 
        //----------------------------------------------------------------------
        inline unsigned int width() const
        {
            return _width;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns the height of the image, in pixels 
        //----------------------------------------------------------------------
        inline unsigned int height() const
        {
            return _height;
        }

        //----------------------------------------------------------------------
        /// @brief  Sets the index of the view contained in the image
        //----------------------------------------------------------------------
        inline void setView(unsigned int view)
        {
            _view = view;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns the index of the view contained in the image
        //----------------------------------------------------------------------
        inline unsigned int view() const
        {
            return _view;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns a pointer to the pixels in RGB (24 bits) format
        ///
        /// @return The pointer to the pixels, or 0 if the image doesn't have a
        ///         PIXELFORMAT_RGB representation
        //----------------------------------------------------------------------
        inline RGBPixel_t* rgbBuffer() const
        {
            return _rgbBuffer;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns an array of pointers to the lines of the RGB
        ///         (24 bits) pixel buffer
        ///
        /// @return The array of pointers, or 0 if the image doesn't have a
        ///         PIXELFORMAT_RGB representation
        //----------------------------------------------------------------------
        inline RGBPixel_t** rgbLines() const
        {
            return _rgbLines;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns a pointer to the pixels in grayscale (8 bits) format
        ///
        /// @return The pointer to the pixels, or 0 if the image doesn't have a
        ///         PIXELFORMAT_GRAY8 representation
        //----------------------------------------------------------------------
        inline byte_t* grayBuffer() const
        {
            return _grayBuffer;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns an array of pointers to the lines of the grayscale
        ///         pixel buffer
        ///
        /// @return The array of pointers, or 0 if the image doesn't have a
        ///         PIXELFORMAT_GRAY8 representation
        //----------------------------------------------------------------------
        inline byte_t** grayLines() const
        {
            return _grayLines;
        }
        
          
        //_____ Attributes __________
    private:
        unsigned int    _pixelFormats;  ///< Available pixel formats for the image
        unsigned int    _width;         ///< Width of the image, in pixels
        unsigned int    _height;        ///< Height of the image, in pixels
        unsigned int    _view;          ///< Index of the view contained in the image

        RGBPixel_t*     _rgbBuffer;     ///< RGB pixel buffer
        RGBPixel_t**    _rgbLines;      ///< Pointer to the lines in the RGB pixel buffer
        
        byte_t*         _grayBuffer;    ///< Grayscale pixel buffer
        byte_t**        _grayLines;     ///< Pointer to the lines in the grayscale pixel buffer
    };
}

#endif

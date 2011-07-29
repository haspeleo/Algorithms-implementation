/** @file   image.cpp
    @author Philip Abbet (philip.abbet@idiap.ch)

    Implementation of the 'Image' class
*/

#include "image.h"
#include <memory.h>
#include <assert.h>

using namespace Mash;
    

/************************* CONSTRUCTION / DESTRUCTION *************************/

Image::Image(unsigned int width, unsigned int height, unsigned int view)
: _pixelFormats(0), _width(width), _height(height), _view(view), _rgbBuffer(0),
  _rgbLines(0), _grayBuffer(0), _grayLines(0)
{
    assert(width > 0);
    assert(height > 0);
}


Image::~Image()
{
    delete[] _rgbBuffer;
    delete[] _rgbLines;
    
    delete[] _grayBuffer;
    delete[] _grayLines;
}


/*********************************** METHODS **********************************/

Image* Image::copy() const
{
    Image* pCopy = new Image(_width, _height, _view);

    pCopy->addPixelFormats(_pixelFormats);
    
    if (_rgbBuffer)
        memcpy(pCopy->_rgbBuffer, _rgbBuffer, _width * _height * sizeof(RGBPixel_t));

    if (_grayBuffer)
        memcpy(pCopy->_grayBuffer, _grayBuffer, _width * _height * sizeof(byte_t));

    return pCopy;
}


void Image::addPixelFormats(unsigned int pixelFormats)
{
    _pixelFormats |= pixelFormats;
    
    if ((pixelFormats & PIXELFORMAT_RGB) && !_rgbBuffer)
    {
        _rgbBuffer = new RGBPixel_t[_width * _height];
        _rgbLines = new RGBPixel_t*[_height];

        RGBPixel_t* pLine = _rgbBuffer;
        for (unsigned int y = 0; y < _height; ++y)
        {
            _rgbLines[y] = pLine;
            pLine += _width;
        }
    }
    
    if ((pixelFormats & PIXELFORMAT_GRAY) && !_grayBuffer)
    {
        _grayBuffer = new byte_t[_width * _height];
        _grayLines = new byte_t*[_height];

        byte_t* pLine = _grayBuffer;
        for (unsigned int y = 0; y < _height; ++y)
        {
            _grayLines[y] = pLine;
            pLine += _width;
        }
    }
}

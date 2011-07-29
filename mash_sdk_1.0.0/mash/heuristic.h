/** @file   heuristic.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Declaration of the 'Heuristic' interface
*/

#ifndef _MASH_HEURISTIC_H_
#define _MASH_HEURISTIC_H_

#include "image.h"


namespace Mash
{
    //--------------------------------------------------------------------------
    /// @brief  Coordinates of a point in an image
    //--------------------------------------------------------------------------
    struct coordinates_t
    {
        unsigned int x;     ///< X position in pixels
        unsigned int y;     ///< Y position in pixels
    };


    //--------------------------------------------------------------------------
    /// @brief  Type of the features computed by the heuristics 
    //--------------------------------------------------------------------------
    typedef float scalar_t;


    //--------------------------------------------------------------------------
    /// @brief  Base class for the heuristics
    ///
    /// A heuristic must compute some features given an image, the coordinates
    /// of a point in this image and the extent of a 'region of interest' around
    /// that point that the MASH system think is relevant for the task.
    ///
    /// The region of interest in a square area, centered on the point. Its
    /// width (and height) is: roi_extent * 2 + 1 (with roi_extent in pixels).
    //--------------------------------------------------------------------------
    class MASH_SYMBOL Heuristic
    {
        //_____ Construction / Destruction __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Constructor
        //----------------------------------------------------------------------
        Heuristic()
        : nb_views(0), roi_extent(0), image(0)
        {
            coordinates.x = 0;
            coordinates.y = 0;
        }

        //----------------------------------------------------------------------
        /// @brief  Destructor
        //----------------------------------------------------------------------
        virtual ~Heuristic() {}


        //_____ Methods to implement __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Called once at the creation of the heuristic
        ///
        /// Pre-computes all the data that will never change during the
        /// life-time of the heuristic
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///
        /// @remark The implementation of this method is optional
        //----------------------------------------------------------------------
        virtual void init() {}

        //----------------------------------------------------------------------
        /// @brief  Called once when the heuristic is destroyed
        ///
        /// Frees the memory allocated by the init() method
        ///
        /// @remark This method must be implemented if init() is used and
        ///         allocated some memory
        //----------------------------------------------------------------------
        virtual void terminate() {}

        //----------------------------------------------------------------------
        /// @brief  Returns the number of features this heuristic computes
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///
        /// @remark Each heuristic must implement this method
        //----------------------------------------------------------------------
        virtual unsigned int dim() = 0;

        //----------------------------------------------------------------------
        /// @brief  Called once per sequence, before any computation 
        ///
        /// Allocates and initializes the data the heuristic will need to
        /// compute features on a stream of images (like a video)
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///
        /// @remark The implementation of this method is optional
        //----------------------------------------------------------------------
        virtual void prepareForSequence() {}

        //----------------------------------------------------------------------
        /// @brief  Called once per sequence, after any computation 
        ///
        /// Frees the memory allocated by the prepareForSequence() method
        ///
        /// @remark This method must be implemented if prepareForSequence() is
        ///         used and allocated some memory
        //----------------------------------------------------------------------
        virtual void finishForSequence() {}

        //----------------------------------------------------------------------
        /// @brief  Called once per image, before any computation 
        ///
        /// Pre-computes from a full image the data the heuristic will need to
        /// compute features at any coordinates in the image
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///     - image
        ///
        /// @remark The implementation of this method is optional
        //----------------------------------------------------------------------
        virtual void prepareForImage() {}

        //----------------------------------------------------------------------
        /// @brief  Called once per image, after any computation 
        ///
        /// Frees the memory allocated by the prepareForImage() method
        ///
        /// @remark This method must be implemented if prepareForImage() is used
        ///         and allocated some memory
        //----------------------------------------------------------------------
        virtual void finishForImage() {}

        //----------------------------------------------------------------------
        /// @brief  Called once per coordinates, before any computation
        ///
        /// Pre-computes the data the heuristic will need to compute features
        /// at the given coordinates
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///     - image
        ///     - coordinates
        ///
        /// @remark The implementation of this method is optional
        //----------------------------------------------------------------------
        virtual void prepareForCoordinates() {}

        //----------------------------------------------------------------------
        /// @brief  Called once per coordinates, after any computation 
        ///
        /// Frees the memory allocated by the prepareForCoordinates() method
        ///
        /// @remark This method must be implemented if prepareForCoordinates()
        ///         is used and allocated some memory
        //----------------------------------------------------------------------
        virtual void finishForCoordinates() {}

        //----------------------------------------------------------------------
        /// @brief  Computes the specified feature
        ///
        /// When this method is called, the following attributes are initialized:
        ///     - nb_views
        ///     - roi_extent
        ///     - image
        ///     - coordinates
        ///
        /// @remark Each heuristic must implement this method
        //----------------------------------------------------------------------
        virtual scalar_t computeFeature(unsigned int feature_index) = 0;


        //_____ Attributes __________
    public:
        unsigned int    nb_views;       ///< Total number of views
        unsigned int    roi_extent;     ///< Extent of the region of interest currently processed
        coordinates_t   coordinates;    ///< Coordinates of the point currently processed
        Image*          image;          ///< The image currently processed
    };


    //--------------------------------------------------------------------------
    /// @brief  Prototype of the function used to create an instance of a
    ///         specific heuristic object
    ///
    /// Each heuristic must have an associated function called 'new_heuristic'
    /// that creates an instance of the heuristic. For instance, if your
    /// heuristic class is 'MyHeuristic', your 'new_heuristic' function must be:
    /// @code
    /// extern "C" Heuristic* new_heuristic()
    /// {
    ///     return new MyHeuristic();
    /// }
    /// @endcode
    //--------------------------------------------------------------------------
    typedef Heuristic* tHeuristicConstructor();
}

#endif

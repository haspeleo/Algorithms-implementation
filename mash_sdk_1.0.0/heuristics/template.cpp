/** Author: YOUR_USERNAME

    TODO: Write a description of your heuristic
*/

#include <mash/heuristic.h>

using namespace Mash;


//------------------------------------------------------------------------------
// Declaration of the heuristic class
//
// TODO: Change the names of the class, the constructor and the destructor. Also
//       change the name of the class in the implementation of each method below
//------------------------------------------------------------------------------
class MyHeuristic: public Heuristic
{
    //_____ Construction / Destruction __________
public:
    MyHeuristic();
    virtual ~MyHeuristic();


    //_____ Implementation of Heuristic __________
public:
    //--------------------------------------------------------------------------
    /// @brief  Called once at the creation of the heuristic
    ///
    /// Pre-computes all the data that will never change during the life-time of
    /// the heuristic
    ///
    /// When this method is called, the 'roi_extent' attribute is initialized
    ///
    /// @remark The implementation of this method is optional
    //--------------------------------------------------------------------------
    virtual void init();

    //--------------------------------------------------------------------------
    /// @brief  Called once when the heuristic is destroyed
    ///
    /// Frees the memory allocated by the init() method
    ///
    /// @remark This method must be implemented if init() is used and allocated
    ///         some memory
    //--------------------------------------------------------------------------
    virtual void terminate();

    //--------------------------------------------------------------------------
    // Returns the number of features this heuristic computes
    //
    // When this method is called, the 'roi_extent' attribute is initialized
    //--------------------------------------------------------------------------
    virtual unsigned int dim();

    //--------------------------------------------------------------------------
    // Called once per image, before any computation 
    //
    // Pre-computes from a full image the data the heuristic will need to compute
    // features at any coordinates in the image
    //
    // When this method is called, the following attributes are initialized:
    //     - roi_extent
    //     - image
    //--------------------------------------------------------------------------
    virtual void prepareForImage();

    //--------------------------------------------------------------------------
    // Called once per image, after any computation 
    //
    // Frees the memory allocated by the prepareForImage() method
    //--------------------------------------------------------------------------
    virtual void finishForImage();

    //--------------------------------------------------------------------------
    // Called once per coordinates, before any computation
    //
    // Pre-computes the data the heuristic will need to compute features at the
    // given coordinates
    //
    // When this method is called, the following attributes are initialized:
    //     - roi_extent
    //     - image
    //     - coordinates
    //--------------------------------------------------------------------------
    virtual void prepareForCoordinates();
    
    //--------------------------------------------------------------------------
    // Called once per coordinates, after any computation 
    //
    // Frees the memory allocated by the prepareForCoordinates() method
    //--------------------------------------------------------------------------
    virtual void finishForCoordinates();

    //--------------------------------------------------------------------------
    // Computes the specified feature
    //
    // When this method is called, the following attributes are initialized:
    //     - roi_extent
    //     - image
    //     - coordinates
    //--------------------------------------------------------------------------
    virtual scalar_t computeFeature(unsigned int feature_index);


    //_____ Attributes __________
protected:
    // TODO: Declare all the attributes you'll need here
};


//------------------------------------------------------------------------------
// Creation function of the heuristic
//
// TODO: Change the name of the instanciated class
//------------------------------------------------------------------------------
extern "C" Heuristic* new_heuristic()
{
    return new MyHeuristic();
}



/************************* CONSTRUCTION / DESTRUCTION *************************/

MyHeuristic::MyHeuristic()
{
    // TODO: Initialization of the attributes that doesn't depend of anything
}


MyHeuristic::~MyHeuristic()
{
    // TODO: Cleanup of the allocated memory still remaining
}


/************************* IMPLEMENTATION OF Heuristic ************************/

void MyHeuristic::init()
{
    // TODO: Initialization of the attributes that depend on the size of the
    // region of interest
}


void MyHeuristic::terminate()
{
    // TODO: Cleanup of the memory allocated by the init() method
}


unsigned int MyHeuristic::dim()
{
    // TODO: Implement it. As an example, here is the implementation of the
    // 'Identity' heuristic:

    // We have has many features than pixels in the region of
    // interest
    unsigned int roi_size = roi_extent * 2 + 1;
    return roi_size * roi_size;
}


void MyHeuristic::prepareForImage()
{
    // TODO: Initialization of the attributes that depend of the whole image
}


void MyHeuristic::finishForImage()
{
    // TODO: Frees the memory allocated by the prepareForImage() method
}


void MyHeuristic::prepareForCoordinates()
{
    // TODO: Initialization of the attributes that depend of the coordinates
}


void MyHeuristic::finishForCoordinates()
{
    // TODO: Frees the memory allocated by the prepareForCoordinates() method
}


scalar_t MyHeuristic::computeFeature(unsigned int feature_index)
{
    // TODO: Implement it. As an example, here is the implementation of the
    // 'Identity' heuristic: 

    // Compute the coordinates of the top-left pixel of the region of interest
    unsigned int x0 = coordinates.x - roi_extent;
    unsigned int y0 = coordinates.y - roi_extent;

    // Compute the coordinates of the pixel corresponding to the feature, in
    // the region of interest
    unsigned int roi_size = roi_extent * 2 + 1;
    unsigned int x = feature_index % roi_size;
    unsigned int y = (feature_index - x) / roi_size;

    // Return the pixel value corresponding to the desired feature
    byte_t** pLines = image->grayLines();
    return (scalar_t) pLines[y0 + y][x0 + x];
}

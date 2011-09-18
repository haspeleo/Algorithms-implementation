/** @file   testheuristic.cpp
    @author Philip Abbet (philip.abbet@idiap.ch)

    Program that test a heuristic, part of the MASH SDK
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/types.h> 
#include <sys/stat.h> 

#include <mash/heuristic.h>
#include <mash/heuristics_manager.h>
#include <mash/image.h>
#include <mash/imageutils.h>
#include <mash-utils/errors.h>
#include <SimpleOpt.h>
#include <FreeImage.h>

using namespace std;
using namespace Mash;


/**************************** COMMAND-LINE PARSING ****************************/

// The valid options
enum
{
    OPT_HELP,
    OPT_VERBOSE,
    OPT_OUTPUT_FORMAT,
    OPT_OUTPUT_SIZE,
    OPT_OUTPUT_RANGE,
};


const CSimpleOpt::SOption COMMAND_LINE_OPTIONS[] = {
    { OPT_HELP,             "-h",           SO_NONE    },
    { OPT_HELP,             "--help",       SO_NONE    },
    { OPT_VERBOSE,          "-v",           SO_NONE    },
    { OPT_VERBOSE,          "--verbose",    SO_NONE    },
    { OPT_OUTPUT_FORMAT,    "--outformat",  SO_REQ_CMB },
    { OPT_OUTPUT_SIZE,      "--outsize",    SO_REQ_CMB },
    { OPT_OUTPUT_RANGE,     "--outrange",   SO_REQ_CMB },
    
    SO_END_OF_OPTIONS
};


// The files
enum
{
    FILE_HEURISTIC,
    FILE_IMAGE,
    FILE_RESULTS,

    FILES_COUNT
};


/******************************** RESULTS FILE ********************************/

// The formats of the results file
enum tOutputFormat
{
    OUTPUTFORMAT_DEFAULT,
    OUTPUTFORMAT_IMAGE,
    OUTPUTFORMAT_CSV,
};


// The default class used to write results in a text file
class TextResultsFile
{
public:
    //_____ Construction / Destruction __________

    TextResultsFile(const std::string& strFileName)
    : firstFeature(true)
    {
        stream.open(strFileName.c_str());
        stream << setprecision(20);
    }

    virtual ~TextResultsFile()
    {
        if (stream.good())
            stream.close();
    }


    //_____ Methods __________

    inline bool good() const { return stream.good(); }

    virtual void writeFeature(scalar_t feature)
    {
        stream << (firstFeature ? "" : " ") << feature;
        firstFeature = false;
    }
    

    //_____ Attributes __________
    ofstream    stream;
    bool        firstFeature;
};


// The class used to write results in a CSV file
class CSVResultsFile : public TextResultsFile
{
public:
    //_____ Construction / Destruction __________

    CSVResultsFile(const std::string& strFileName, unsigned int nbColumns)
    : TextResultsFile(strFileName), nbColumns(nbColumns), currentColumn(0)
    {
    }

    virtual ~CSVResultsFile()
    {
    }


    //_____ Methods __________

    virtual void writeFeature(scalar_t feature)
    {
        stream << feature;
        
        ++currentColumn;
        if (currentColumn == nbColumns)
        {
            stream << endl;
            currentColumn = 0;
        }
        else
        {
            stream << ",";
        }
    }
    

    //_____ Attributes __________
    unsigned int nbColumns;
    unsigned int currentColumn;
};


/********************************** FUNCTIONS *********************************/

void showUsage(const std::string& strApplicationName)
{
    cout << "MASH Heuristic Tester" << endl
         << "Usage: " << strApplicationName << " [options] <heuristic name> <image name> <results file>" << endl
         << endl
         << "With:" << endl
         << "    <heuristic name>: Name of the heuristic to test. The program will look in the" << endl
         << "                      'heuristics' folder for a file with that name." << endl
         << "    <image name>:     Path to the image file that will be processed by the" << endl
         << "                      heuristic. The path can be relative to the 'data' folder." << endl
         << "    <results file>:   All the features computed by the heuristic will be written" << endl
         << "                      to that file." << endl
         << endl
         << "Options:" << endl
         << "    --help, -h:           Display this help" << endl
         << "    --verbose, -v:        Display the features computed by heuristic" << endl
         << "    --outformat=<format>: Change the format of the results file. Valid values:" << endl 
         << "                           * default: The same output than the one of the program" << endl
         << "                                      in verbose mode (default value)" << endl
         << "                           * image:   A PNG image" << endl
         << "                           * csv:     A CSV (Comma-separated values) file" << endl
         << endl
         << "When the results file is an image, the following options must be supplied:" << endl
         << "    --outsize=<width>x<height>: Dimensions of the image. <width> * <height> must" << endl
         << "                                be equal to the dimension of the features vector" << endl
         << "                                returned by the heuristic" << endl
         << "    --outrange=<min>..<max>:    Minimum and maximum value of the features. Used" << endl
         << "                                to map the range of the features into the one of" << endl
         << "                                the pixels of the image. The features outside" << endl
         << "                                this range are clamped." << endl
         << endl
         << "When the results file is a CSV file, the following options can be supplied:" << endl
         << "    --outsize=<nbcolumns>: Number of columns (default: 1)" << endl
         << endl
         << "Examples:" << endl
         << "    * " << strApplicationName << " my_new_heuristic car.ppm results.txt" << endl
         << "    * " << strApplicationName << " examples/identity cup.ppm results.txt" << endl
         << "    * " << strApplicationName << " --outformat=image --outsize=128x128 --outrange=0.0..255.0 examples/identity cup.ppm results.png" << endl
         << "    * " << strApplicationName << " --outformat=csv examples/identity cup.ppm results.csv" << endl;
}


void writeInfos(std::ostream* stream, CSimpleOpt* args, Image* pImage,
                Image* pOriginalImage, Heuristic* pHeuristic,
                const coordinates_t& coordinates, unsigned int roi_extent,
                const std::string& strPrefix = "")
{
    (*stream) << strPrefix << "Image:" << endl;
    (*stream) << strPrefix << "  File:          " << args->File(FILE_IMAGE) << endl;
    
    if (pOriginalImage)
    {
        (*stream) << strPrefix << "  Original Size: " << pOriginalImage->width() << "x" << pOriginalImage->height() << endl;
        (*stream) << strPrefix << "  Used size:     " << pImage->width() << "x" << pImage->height() << endl;
    }
    else
    {
        (*stream) << strPrefix << "  Size:          " << pImage->width() << "x" << pImage->height() << endl;
    }

    (*stream) << strPrefix << "  Format:        " << (pImage->hasPixelFormat(Image::PIXELFORMAT_RGB)  ? "'RGB' " : "")
                                                  << (pImage->hasPixelFormat(Image::PIXELFORMAT_GRAY)  ? "'Grayscale' " : "")
                                                  << endl;

    (*stream) << strPrefix << "Parameters:" << endl;
    (*stream) << strPrefix << "  Coordinates:   (" << coordinates.x << ", " << coordinates.y << ")" << endl;
    (*stream) << strPrefix << "  ROI extent:    " << roi_extent << endl;
    (*stream) << strPrefix << "  ROI size:      " << roi_extent * 2 + 1 << endl;

    (*stream) << strPrefix << "Heuristic:" << endl;
    (*stream) << strPrefix << "  Name:          " << args->File(FILE_HEURISTIC) << endl;
    (*stream) << strPrefix << "  Dimension:     " << pHeuristic->dim() << endl;

    (*stream) << endl;
}


int main(int argc, char** argv)
{
    // Declarations
#ifdef MASH_HEURISTICS_DIR
    HeuristicsManager   manager(MASH_HEURISTICS_DIR);
#else
    HeuristicsManager   manager("heuristics");
#endif
    coordinates_t       coordinates;
    unsigned int        roi_extent      = 0;
    Image*              pOriginalImage  = 0;
    Image*              pImage          = 0;
    Heuristic*          pHeuristic      = 0;
    bool                bVerbose        = false;
    tOutputFormat       outputFormat    = OUTPUTFORMAT_DEFAULT;
    unsigned int        outputWidth     = 1;
    unsigned int        outputHeight    = 0;
    float               outputRangeMin  = 0.0f;
    float               outputRangeMax  = 0.0f;
    TextResultsFile*    pOutputFile     = 0;
    FIBITMAP*           pOutputImage    = 0;


    // Parse the command-line parameters
    CSimpleOpt args(argc, argv, COMMAND_LINE_OPTIONS);
    while (args.Next())
    {
        if (args.LastError() == SO_SUCCESS)
        {
            switch (args.OptionId())
            {
                case OPT_HELP:
                    showUsage(argv[0]);
                    return 0;
                
                case OPT_VERBOSE:
                    bVerbose = true;
                    break;

                case OPT_OUTPUT_FORMAT:
                    {
                        string strFormat = args.OptionArg();
                        if (strFormat == "image")
                        {
                            outputFormat = OUTPUTFORMAT_IMAGE;
                        }
                        else if (strFormat == "csv")
                        {
                            outputFormat = OUTPUTFORMAT_CSV;
                        }
                        else if (strFormat != "default")
                        {
                            cerr << "Unknown output format: " << strFormat << endl;
                            return -1;
                        }
                    }
                    break;

                case OPT_OUTPUT_SIZE:
                    {
                        string strSize = args.OptionArg();
                        
                        if (outputFormat == OUTPUTFORMAT_IMAGE)
                        {
                            size_t offset = strSize.find("x");
                            if (offset != string::npos)
                            {
                                outputWidth = atoi(strSize.substr(0, offset).c_str());
                                outputHeight = atoi(strSize.substr(offset + 1).c_str());
                            }

                            if ((outputWidth == 0) || (outputHeight == 0))
                            {
                                cerr << "Invalid output size: " << strSize << endl;
                                return -1;
                            }
                        }
                        else if (outputFormat == OUTPUTFORMAT_CSV)
                        {
                            outputWidth = atoi(strSize.c_str());

                            if (outputWidth == 0)
                            {
                                cerr << "Invalid number of columns: " << strSize << endl;
                                return -1;
                            }
                        }
                    }
                    break;

                case OPT_OUTPUT_RANGE:
                    {
                        string strRange = args.OptionArg();

                        size_t offset = strRange.find("..");
                        if (offset != string::npos)
                        {
                            outputRangeMin = (float) atof(strRange.substr(0, offset).c_str());
                            outputRangeMax = (float) atof(strRange.substr(offset + 2).c_str());
                        }

                        if (outputRangeMin >= outputRangeMax)
                        {
                            cerr << "Invalid output range: " << strRange << endl;
                            return -1;
                        }
                    }
                    break;
            }
        }
        else
        {
            cerr << "Invalid argument: " << args.OptionText() << endl;
            return -1;
        }
    }

    if (args.FileCount() != FILES_COUNT)
    {
        cerr << "Invalid files list" << endl;
        showUsage(argv[0]);
        return -1;
    }


    // Load the image
    string strImagePath = args.File(FILE_IMAGE);
    struct stat fileInfo;
    if (stat(strImagePath.c_str(), &fileInfo) != 0)
    {
#ifdef MASH_DATA_DIR
        strImagePath = string(MASH_DATA_DIR) + strImagePath;
#else
        strImagePath = string("../data") + strImagePath;
#endif
    }

    pImage = ImageUtils::loadImage(strImagePath);
    if (!pImage)
    {
        cerr << "Failed to open the image '" << args.File(FILE_IMAGE) << "'" << endl;
        return -1;
    }


    // Compute the coordinates of the point to process and the extent of the
    // region of interest
    unsigned int dim = std::max(pImage->width(), pImage->height());
    if (dim % 2 == 0)
        --dim;

    // Add black pixels to the image to make it square if necessary
    if ((pImage->width() < dim) || (pImage->height() < dim))
    {
        pOriginalImage = pImage;
        
        RGBPixel_t paddingColor = { 0 };
        pImage = ImageUtils::scale(pOriginalImage,
                                   (pOriginalImage->width() < dim) ? dim : pOriginalImage->width(),
                                   (pOriginalImage->height() < dim) ? dim : pOriginalImage->height(),
                                   paddingColor);
    }
    
    roi_extent = (dim - 1) >> 1;
    unsigned int roi_size = roi_extent * 2 + 1;
    
    coordinates.x = roi_extent + ((pImage->width() - roi_size) >> 1);
    coordinates.y = roi_extent + ((pImage->height() - roi_size) >> 1);


    // Load the heuristic
    pHeuristic = manager.create(args.File(FILE_HEURISTIC));
    if (!pHeuristic)
    {
        string description = manager.getLastErrorDescription();
        if (description.empty())
            description = getErrorDetailedDescription(manager.getLastError());

        cerr << "Failed to load the heuristic '" << args.File(FILE_HEURISTIC)
             << "', reason: " << description << endl;
        
        delete pImage;
        return -1;
    }

    pHeuristic->roi_extent = roi_extent;
    pHeuristic->init();

    
    // Retrieve the dimension of the heuristic
    if (pHeuristic->dim() == 0)
    {
        cerr << "Invalid heuristic dimension: the heuristic doesn't report any features. Please implement the dim() method." << endl;
        delete pHeuristic;
        delete pImage;
        return -1;
    }
    

    // Create the results file
    if (outputFormat == OUTPUTFORMAT_DEFAULT)
    {
        pOutputFile = new TextResultsFile(args.File(FILE_RESULTS));
    }
    else if (outputFormat == OUTPUTFORMAT_CSV)
    {
        pOutputFile = new CSVResultsFile(args.File(FILE_RESULTS), outputWidth);
    }
    else if (outputFormat == OUTPUTFORMAT_IMAGE)
    {
        if (outputWidth * outputHeight == pHeuristic->dim())
        {
            FreeImage_Initialise(true);
            pOutputImage = FreeImage_AllocateT(FIT_BITMAP, outputWidth, outputHeight, 24);
        }
        else
        {
            cerr << endl << "The dimensions of the results image (" << outputWidth << "x"
                 << outputHeight << ") don't match the number of feature computed by the heuristic ("
                 << pHeuristic->dim() << "). The results image will not be created." << endl << endl;
        }
    }

    if (pOutputFile && !pOutputFile->good())
    {
        cerr << "Can not create the results file '" << args.File(FILE_RESULTS) << "'" << endl;
        delete pOutputFile;
        delete pHeuristic;
        delete pImage;
        return -1;
    }

    
    // Write some informations to the console and the results file (if any)
    writeInfos(&cout, &args, pImage, pOriginalImage, pHeuristic, coordinates, roi_extent);

    if (outputFormat == OUTPUTFORMAT_DEFAULT)
        writeInfos(&pOutputFile->stream, &args, pImage, pOriginalImage, pHeuristic, coordinates, roi_extent, "# ");


    // Add the missing pixel formats to the image
    ImageUtils::convertImageToPixelFormats(pImage, Image::PIXELFORMAT_ALL);


    // Compute all the features of the heuristic
    pHeuristic->image = pImage;
    pHeuristic->prepareForImage();

    pHeuristic->coordinates = coordinates;
    pHeuristic->prepareForCoordinates();

    unsigned int x = 0;
    unsigned int y = 0;
    for (unsigned int i = 0; i < pHeuristic->dim(); ++i)
    {
        scalar_t feature = pHeuristic->computeFeature(i);
        
        if (bVerbose)
            cout << (i > 0 ? " " : "") << feature;
        
        if (pOutputFile)
        {
            pOutputFile->writeFeature(feature);
        }
        else if (pOutputImage)
        {
            scalar_t clampedFeature = std::max(outputRangeMin, std::min(feature, outputRangeMax));
            byte_t color = (byte_t) (255 * (clampedFeature - outputRangeMin) / (outputRangeMax - outputRangeMin));

            RGBQUAD rgbColor;
            rgbColor.rgbRed = color;
            rgbColor.rgbGreen = color;
            rgbColor.rgbBlue = color;
            FreeImage_SetPixelColor(pOutputImage, x, outputHeight - 1 - y, &rgbColor);
            
            ++x;
            if (x >= outputWidth)
            {
                x = 0;
                ++y;
            }
        }
    }
    
    pHeuristic->finishForCoordinates();
    pHeuristic->finishForImage();


    // Write the output image (if any)
    if (pOutputImage)
        FreeImage_Save(FIF_PNG, pOutputImage, args.File(FILE_RESULTS));

    cout << endl;

    pHeuristic->terminate();

    cout << "Test terminated correctly." << endl;


    // Cleanup
    if (pOutputImage)
    {
        FreeImage_Unload(pOutputImage);
        FreeImage_DeInitialise();
    }

    delete pOutputFile;
    delete pHeuristic;
    delete pOriginalImage;
    delete pImage;

    return 0;
}

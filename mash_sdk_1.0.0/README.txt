********************************************************************************
*                                                                              *
*                              MASH SDK 1.0.0                                  *
*                                                                              *
********************************************************************************

This SDK can be used to develop new heuristics.

It is released under the BSD license. The license can be found in the
LICENSE.txt file.

The up-to-date information about using the SDK can be found on the Wiki of the
MASH project:

  http://mash-project.eu/wiki/index.php/Heuristics_development


________________________________________________________________________________

Requirements:
-------------

You'll need to install CMake 2.6 (or higher) to compile the SDK. Download it at:

  http://www.cmake.org/cmake/resources/software.html

CMake is available both as a command-line tool and a GUI-based one, for Windows,
Linux and MacOS X.


________________________________________________________________________________

Quick start about heuristic development under Linux/MacOS X:
------------------------------------------------------------

We'll use the command-line here to generate the Makefiles and compile the SDK.

(Note: On MacOS X, you can generate a XCode project instead of the Makefiles if
you want. See the Wiki for more details).

  ---------------------------- snip snip -----------------------------
    tar -xvzf mash_sdk_1.0.0.tar.gz
    cd mash_sdk_1.0.0
    mkdir build
    cd build
    cmake ..
    make
    cd bin
    ./testheuristic examples/identity car.ppm results.txt
  ---------------------------- snip snip -----------------------------

You should obtain:

  ---------------------------- snip snip -----------------------------
   Image:
     File:          car.ppm
     Size:          128x128
     Format:        'RGB' 
   Parameters:
     Coordinates:   (63, 63)
     ROI extent:    63
     ROI size:      127
   Heuristic:
     Name:          examples/identity
     Dimension:     16129

   Test terminated correctly.
  ---------------------------- snip snip -----------------------------


________________________________________________________________________________

Quick start about heuristic development under Windows:
------------------------------------------------------------

The usual way is to use the CMake-GUI to generate a Visual Studio solution. Both
Visual Studio 2005, 2008 and 2010 are supported. The (free) Visual C++ 2010
Express compiler also works:

  http://www.microsoft.com/express/

See the wiki for more details about the compilation of the SDK on Windows.


________________________________________________________________________________

Implementing your own heuristic:
--------------------------------

Please refer to the wiki for a tutorial about heuristic development and detailed
explanation of the API:

  http://mash-project.eu/wiki/index.php/Heuristics_development


--
June 20, 2011

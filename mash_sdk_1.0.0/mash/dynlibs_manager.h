/** @file   dynlibs_manager.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Declaration of the 'DynlibsManager' class
*/

#ifndef _MASH_DYNLIBSMANAGER_H_
#define _MASH_DYNLIBSMANAGER_H_

#include "dynlibs_manager_delegate_interface.h"
#include <mash-utils/declarations.h>
#include <string>
#include <map>


#if MASH_PLATFORM == MASH_PLATFORM_WIN32
#    define DYNLIB_HANDLE           hInstance
#    define DYNLIB_LOAD( a )        LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#    define DYNLIB_GETSYM( a, b )   GetProcAddress( a, b )
#    define DYNLIB_UNLOAD( a )      !FreeLibrary( a )

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#else
#    define DYNLIB_HANDLE           void*
#    define DYNLIB_LOAD( a )        dlopen( a, RTLD_NOW | RTLD_LOCAL )
#    define DYNLIB_GETSYM( a, b )   dlsym( a, b )
#    define DYNLIB_UNLOAD( a )      dlclose( a )

#endif


namespace Mash
{
    //--------------------------------------------------------------------------
    /// @brief  Base class for the 'dynamic libraries manager'
    ///
    /// Contains the methods common to all the manager classes that needs to
    /// load dynamic libraries implementing a particural interface.
    ///
    /// The dynamic libraries are identified by a string with one of the
    /// following formats:
    ///   - <author>/<name>/<version>
    ///   - <author>/<name>
    ///   - <name>
    ///
    /// This string is used to determine the actual name of the dynamic library
    /// file. For example:
    ///
    ///   * Name: examples/something
    ///   -> (on linux): <root>/examples/libsomething.so
    ///   -> (on windows): <root>/examples/something.dll
    ///
    ///   * Name: examples/something/2
    ///   -> (on linux): <root>/examples/libsomething_v2.so
    ///   -> (on windows): <root>/examples/something_v2.dll
    ///
    ///   * Name: something
    ///   -> (on linux): <root>/libsomething.so
    ///   -> (on windows): <root>/something.dll
    ///
    /// It is recommended to use the same naming scheme for the source code
    /// files implementing the dynamic libraries.
    //--------------------------------------------------------------------------
    class MASH_SYMBOL DynlibsManager
    {
        //_____ Construction / Destruction __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Constructor
        ///
        /// @param  strRootFolder   Path to the folder containing all the dynamic
        ///                         libraries
        //----------------------------------------------------------------------
        DynlibsManager(const std::string& strRootFolder = "");

        //----------------------------------------------------------------------
        /// @brief  Destructor
        //----------------------------------------------------------------------
        ~DynlibsManager();


        //_____ Methods __________
    public:
        //----------------------------------------------------------------------
        /// @brief  Returns the last error that occured
        //----------------------------------------------------------------------
        inline tError getLastError() const { return _lastError; }

        //----------------------------------------------------------------------
        /// @brief  Returns a description of the last error that occured
        //----------------------------------------------------------------------
        std::string getLastErrorDescription() const;

        //----------------------------------------------------------------------
        /// @brief  Load the specified dynamic library
        ///
        /// @param  strName     Name of the dynamic library
        /// @return             Handle of the library, 0 if failed
        //----------------------------------------------------------------------
        DYNLIB_HANDLE loadDynamicLibrary(const std::string& strName);

        //----------------------------------------------------------------------
        /// @brief  Sets the delegate to use
        ///
        /// @param  strName     Name of the dynamic library
        /// @return             Handle of the library, 0 if failed
        //----------------------------------------------------------------------
        inline void setDelegate(IDynlibsManagerDelegate* pDelegate)
        {
            _pDelegate = pDelegate;
        }

        //----------------------------------------------------------------------
        /// @brief  Returns the path to the dynamic library file corresponding
        ///         to the specified name
        ///
        /// @param  strName     Name of the dynamic library
        /// @return             Path to the dynamic library, relative to the
        ///                     folder containing them all (see the constructor)
        //----------------------------------------------------------------------
        static std::string getDynamicLibraryPath(const std::string& strName);

        //----------------------------------------------------------------------
        /// @brief  Returns the path to the source file corresponding to the
        ///         specified name (as long as the same naming scheme than for
        ///         the dynamic libraries is used)
        ///
        /// @param  strName     Name of the dynamic library
        /// @return             Path to the source file, relative to the folder
        ///                     containing them all (see the constructor)
        //----------------------------------------------------------------------
        static std::string getSourceFilePath(const std::string& strName);

    protected:
        //----------------------------------------------------------------------
        /// @brief  Split the name of a dynamic library
        ///
        /// @param      strName             Full name of the dynamic library
        /// @param[out] strUserName         User name
        /// @param[out] strHeuristicName    Dynamic library name
        /// @param[out] strVersion          Version
        //----------------------------------------------------------------------
        static void splitName(const std::string& strName,
                              std::string* strUserName,
                              std::string* strDynlibName,
                              std::string* strVersion);


        //_____ Internal types __________
    protected:
        typedef std::map<std::string, DYNLIB_HANDLE>    tHandlesList;
        typedef tHandlesList::iterator                  tHandlesIterator;


        //_____ Attributes __________
    protected:
        std::string                 _strRootFolder;
        tHandlesList                _handles;
        IDynlibsManagerDelegate*    _pDelegate;
        tError                      _lastError;
        std::string                 _strLoadingError;
    };
}

#endif

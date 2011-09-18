/** @file   dynlibs_manager.cpp
    @author Philip Abbet (philip.abbet@idiap.ch)

    Implementation of the 'DynlibsManager' class
*/

#include "dynlibs_manager.h"
#include <mash-utils/stringutils.h>
#include <assert.h>
#include <iostream>

#if MASH_PLATFORM == MASH_PLATFORM_WIN32
#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>
#else
#   include <dlfcn.h>
#endif

using namespace std;
using namespace Mash;


/************************* CONSTRUCTION / DESTRUCTION *************************/

DynlibsManager::DynlibsManager(const std::string& strRootFolder)
: _strRootFolder(strRootFolder), _pDelegate(0), _lastError(ERROR_NONE)
{
}


DynlibsManager::~DynlibsManager()
{
    tHandlesIterator iter, iterEnd;
    int ret;
    
    if (_pDelegate)
        _pDelegate->enableWarden();

    for (iter = _handles.begin(), iterEnd = _handles.end(); iter != iterEnd; ++iter)
    {
        if (iter->second)
            ret = DYNLIB_UNLOAD(iter->second);
    }

    if (_pDelegate)
        _pDelegate->disableWarden();
}


/*********************************** METHODS **********************************/

std::string DynlibsManager::getLastErrorDescription() const
{
    if (_lastError == ERROR_NONE)
        return "";
    
    if (_lastError == ERROR_DYNLIB_LOADING)
        return _strLoadingError;

    return "";
}


std::string DynlibsManager::getDynamicLibraryPath(const std::string& strName)
{
    // Assertions
    assert(!strName.empty());
        
    // Declarations
    string strUserName;
    string strDynlibName;
    string strVersion;
    string strLibrary;
    
    splitName(strName, &strUserName, &strDynlibName, &strVersion);
    
#if MASH_PLATFORM == MASH_PLATFORM_WIN32
    if (!strUserName.empty())
        strLibrary += strUserName + "\\";

#   if MASH_IDE_USED
    strLibrary += string(CMAKE_INTDIR) + "\\";
#   endif
            
    strLibrary += strDynlibName;
    
    if (!strVersion.empty() && (strVersion != "1"))
         strLibrary += "_v" + strVersion;
         
    strLibrary += ".dll";
#else
    if (!strUserName.empty())
        strLibrary += strUserName + "/";
        
#   if MASH_IDE_USED
    strLibrary += string(CMAKE_INTDIR) + "/";
#   endif

    strLibrary += "lib" + strDynlibName;
    
    if (!strVersion.empty() && (strVersion != "1"))
         strLibrary += "_v" + strVersion;
         
    strLibrary += ".so";
#endif

    return strLibrary;
}


std::string DynlibsManager::getSourceFilePath(const std::string& strName)
{
    // Assertions
    assert(!strName.empty());

    // Declarations
    string strUserName;
    string strDynlibName;
    string strVersion;
    string strSourceFile;

    splitName(strName, &strUserName, &strDynlibName, &strVersion);

#if MASH_PLATFORM == MASH_PLATFORM_WIN32
    if (!strUserName.empty())
        strSourceFile += strUserName + "\\";

    strSourceFile += strDynlibName;

    if (!strVersion.empty() && (strVersion != "1"))
         strSourceFile += "_v" + strVersion;

    strSourceFile += ".cpp";
#else
    if (!strUserName.empty())
        strSourceFile += strUserName + "/";

    strSourceFile += strDynlibName;

    if (!strVersion.empty() && (strVersion != "1"))
         strSourceFile += "_v" + strVersion;

    strSourceFile += ".cpp";
#endif

    return strSourceFile;
}


DYNLIB_HANDLE DynlibsManager::loadDynamicLibrary(const std::string& strName)
{
    // Assertions
    assert(!strName.empty());

    // Declarations
    DYNLIB_HANDLE handle;

    // Determine if the dynamic library is already loaded
    tHandlesIterator iter = _handles.find(strName);
    if (iter == _handles.end())
    {
        // Retrieve the path to the dynamic library
        string strLibrary = _strRootFolder;
#if MASH_PLATFORM == MASH_PLATFORM_WIN32
        if (!StringUtils::endsWith(_strRootFolder, "\\"))
            strLibrary += "\\";
#else
        if (!StringUtils::endsWith(_strRootFolder, "/"))
            strLibrary += "/";
#endif
        strLibrary += getDynamicLibraryPath(strName);

        // Load the dynamic library
        if (_pDelegate)
            _pDelegate->enableWarden();

        handle = DYNLIB_LOAD(strLibrary.c_str());

        if (_pDelegate)
            _pDelegate->disableWarden();

        if (!handle)
        {
#if MASH_PLATFORM != MASH_PLATFORM_WIN32
            const char* e = dlerror();
            if (e)
                _strLoadingError = e;

            cout << _strLoadingError << endl;
#endif
            _lastError = ERROR_DYNLIB_LOADING;
            return 0;
        }
        
        // Add it to the list
        _handles[strName] = handle;
    }
    else
    {
        handle = iter->second;
    }

    if (handle == 0)
    {
        _lastError = ERROR_DYNLIB_LOADING;
        return 0;
    }
    
    return handle;
}


void DynlibsManager::splitName(const std::string& strName,
                               std::string* strUserName,
                               std::string* strDynlibName,
                               std::string* strVersion)
{
    // Assertions
    assert(!strName.empty());

    size_t offset = strName.find("/");
    if (offset != string::npos)
    {
        *strUserName = strName.substr(0, offset);

        size_t offset2 = strName.find("/", offset + 1);
        if (offset2 != string::npos)
        {
            *strDynlibName = strName.substr(offset + 1, offset2 - offset - 1);
            *strVersion = strName.substr(offset2 + 1);
        }
        else
        {
            *strDynlibName = strName.substr(offset + 1);
            *strVersion = "";
        }
    }
    else
    {
        *strUserName = "";
        *strDynlibName = strName;
        *strVersion = "";
    }
}

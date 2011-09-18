/** @file   heuristics_manager.cpp
    @author Philip Abbet (philip.abbet@idiap.ch)

    Implementation of the 'HeuristicsManager' class
*/

#include "heuristics_manager.h"
#include <assert.h>

#if MASH_PLATFORM == MASH_PLATFORM_WIN32
#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>
#else
#   include <dlfcn.h>
#endif

using namespace std;
using namespace Mash;


/************************* CONSTRUCTION / DESTRUCTION *************************/

HeuristicsManager::HeuristicsManager(const std::string& strRootFolder)
: DynlibsManager(strRootFolder)
{
}


HeuristicsManager::~HeuristicsManager()
{
}


/*********************************** METHODS **********************************/

Heuristic* HeuristicsManager::create(const std::string& strName)
{
    // Assertions
    assert(!strName.empty());

    _lastError = ERROR_NONE;

    // Retrieve the construction function of the heuristic
    tHeuristicConstructor* constructor = getHeuristicConstructor(strName);
    if (!constructor)
        return 0;
    
    if (_pDelegate)
        _pDelegate->enableWarden();
    
    // Instantiate a new heuristic
    Heuristic* pHeuristic = constructor();

    if (_pDelegate)
        _pDelegate->disableWarden();
    
    return pHeuristic;
}


tHeuristicConstructor* HeuristicsManager::getHeuristicConstructor(const std::string& strHeuristic)
{
    // Assertions
    assert(!strHeuristic.empty());

    // Declarations
    DYNLIB_HANDLE           handle;
    tHeuristicConstructor*  constructor;

    // Load the dynamic library
    handle = loadDynamicLibrary(strHeuristic);
    if (!handle)
    {
        _lastError = ERROR_DYNLIB_LOADING;
        return 0;
    }

    // Retrieve the construction function
    constructor = (tHeuristicConstructor*) DYNLIB_GETSYM(handle, "new_heuristic");

    if (!constructor)
    {
        int ret = DYNLIB_UNLOAD(handle);
        _handles[strHeuristic] = 0;
        _lastError = ERROR_HEURISTIC_CONSTRUCTOR;
    }
    
    return constructor;
}

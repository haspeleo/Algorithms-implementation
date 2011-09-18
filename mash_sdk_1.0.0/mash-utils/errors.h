/** @file   utils.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Utility functions  
*/

#ifndef _MASH_UTILS_H_
#define _MASH_UTILS_H_

#include "declarations.h"
#include <string>


namespace Mash
{
    extern MASH_SYMBOL std::string getErrorDescription(tError error);
    extern MASH_SYMBOL std::string getErrorDetailedDescription(tError error);
}

#endif

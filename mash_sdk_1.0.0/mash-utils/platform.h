/** @file   platform.h
    @author Philip Abbet (philip.abbet@idiap.ch)

    Platform-specific declarations 
*/

#ifndef _MASH_PLATFORM_H_
#define _MASH_PLATFORM_H_

#define MASH_PLATFORM_WIN32 1
#define MASH_PLATFORM_LINUX 2
#define MASH_PLATFORM_APPLE 3

#if defined( __WIN32__ ) || defined( _WIN32 )
#   define MASH_PLATFORM MASH_PLATFORM_WIN32

#elif defined( __APPLE_CC__)
#   define MASH_PLATFORM MASH_PLATFORM_APPLE

#else
#   define MASH_PLATFORM MASH_PLATFORM_LINUX
#endif


/// Used to export symbols from library
#if MASH_PLATFORM == MASH_PLATFORM_WIN32
#	ifdef MASH_EXPORTS
#		define MASH_SYMBOL __declspec(dllexport)
#	else
#		define MASH_SYMBOL __declspec(dllimport)
#	endif
#else
#	define MASH_SYMBOL
#endif

#endif

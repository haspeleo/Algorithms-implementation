//<html><body><pre>

/*
 * Example ATM simulation - file sysdep.h
 *
 * This file contains declarations that are specific to the platform on
 * which the system is being implemented
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */


// Comment out the following if the c++ compiler in use supports the new
// ANSI bool type

// typedef int  bool; static const bool false = 0, true = 1;

// Comment out the following if NULL is somehow predefined

#ifndef NULL
#define NULL ((void *) 0)
#endif

// Change this if a different character is needed for terminal bell ringing

#define BELL "\07"

// If a DEC VTxxx compatible terminal is being used, we can draw very nice
// fancy boxes.  If not, we will have to use some "vanilla" symbols.
// The fancy graphics only look their best if the terminal is in 8 bit mode,
// so that graphic characters are redrawn properly on refresh.

// Comment out the next #define if VTxxx compatibility is not available, or
// if the terminal/terminal emulator does not handle 8 bit characters and
// you don't like what happens on redraw.

#define VTXXX

#ifdef VTXXX

#define ESC "\033"
#define GRAPHICS_INIT   ESC"(B"ESC")0"ESC"~"
#define GRAPHICS_ON     "\016"
#define GRAPHICS_OFF    "\017"
#define UL_CORNER       "\354"
#define UR_CORNER       "\353"
#define LL_CORNER       "\355"
#define LR_CORNER       "\352"
#define SIDE_LINE       "\370"
#define TOP_BOTTOM      "\361"

#else

#define GRAPHICS_INIT   ""
#define GRAPHICS_ON     ""
#define GRAPHICS_OFF    ""
#define UL_CORNER       "+"
#define UR_CORNER       "+"
#define LL_CORNER       "+"
#define LR_CORNER       "+"
#define SIDE_LINE       "|"
#define TOP_BOTTOM      "-"

#endif

// The curses.h file on the Linux system I used depended on a type definition
// for speed_t that didn't exist - so supply it.  Delete this if using Linux
// and your version doesn't have this problem.

#ifdef __linux__
#define speed_t short
#endif

//</pre></body></html>

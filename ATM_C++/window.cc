//<html><body><pre>

/*
 * Example ATM simulation - file window.cc
 *
 * This file implements a window class on top of the curses package to provide
 * a simple, portable way of representing the ATM on text-based terminals,
 * as declared in window.h
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include <string.h>
#include "sysdep.h"
#include "window.h"

// Curses requires us to call initscr() once.  We handle this by keeping a
// count of windows we have created - initalized to zero and incremented for
// each window, and calling initscr() for the first one only.  We also use
// this opportunity to do other setup things.

static int windowCount = 0;

Window::Window(int lines, int cols, int begin_y, int begin_x)
  { 
    if (windowCount ++ == 0)
      { initscr();
        printf(GRAPHICS_INIT);
      }
    _Cwindow = newwin(lines, cols, begin_y, begin_x);
    scrollok(_Cwindow, 1);
  }

// Curses also wants us to call endwin once upon termination.  We handle
// this by decrementing the windowCount in the destructor, calling it just
// the windowCount becomes 0

Window::~Window()
  { if (-- windowCount == 0)
       endwin();
  }

Window & Window::operator << (char c)
  { waddch(_Cwindow, c); 
    return * this;
  }

Window & Window::operator << (const char * str)
  { 
#ifdef VMS
    waddstr(_Cwindow, (char *) str); // VMS header should declare parameter
                                     // as const char *, but doesn't
#else
    waddstr(_Cwindow, str); 
#endif
     return * this;
  }

void Window::putCursor(int y, int x)
  { wmove(_Cwindow, y, x); }


Window & Window::operator >> (char & c)
  { wrefresh(_Cwindow);
    c = wgetch(_Cwindow);
    return * this;
  }

Window & Window::operator >> (char * str)
  { wrefresh(_Cwindow);
    wgetstr(_Cwindow, str); 
    return * this;
  }

char Window::inkey(char * allowable)
  {
    noecho();
    crmode();
    nonl();
    char c;
    do
      { c = wgetch(_Cwindow);
        if (allowable == NULL || strchr(allowable, c) != NULL) break;
        (* this) << bell;
      }
    while (1);
    nl();
    nocrmode();
    echo();
    return c;
  }

Window & clearW(Window & window)
  { wclear(window.Cwindow()); 
    wmove(window.Cwindow(), 0, 0);
    return window;
  }

Window & refreshW(Window & window)
  { wrefresh(window.Cwindow()); 
    return window;
  }

Window & bell(Window & window)
  { printf(BELL);
    fflush(stdout);
    return window;
  }

BoxedWindow::BoxedWindow(char * legend, 
                         int lines, int cols, int begin_y, int begin_x)
  : Window(lines - 2, cols - 2, begin_y + 1, begin_x + 1)
  {
    // Draw the fancy box.

    printf(GRAPHICS_ON);
    wmove(stdscr, begin_y, begin_x);
    waddstr(stdscr, UL_CORNER);
    int col;
    for (col = begin_x + 1; col < begin_x + cols - 1; col ++)
        if (col - begin_x <= strlen(legend))
            waddch(stdscr, legend[col - begin_x - 1]);
        else
            waddstr(stdscr, TOP_BOTTOM);
    waddstr(stdscr, UR_CORNER);
    int line;
    for (line = begin_y + 1; line < begin_y + lines - 1; line ++) 
      {
        wmove(stdscr, line, begin_x);
        waddstr(stdscr, SIDE_LINE);
        wmove(stdscr, line, begin_x + cols - 1);
        waddstr(stdscr, SIDE_LINE);
      }
    wmove(stdscr, begin_y + lines - 1, begin_x);
    waddstr(stdscr, LL_CORNER);
    for (col = begin_x + 1; col < begin_x + cols - 1; col ++)
        waddstr(stdscr, TOP_BOTTOM);
    waddstr(stdscr, LR_CORNER);
    wrefresh(stdscr);
    printf(GRAPHICS_OFF);
  }

//</pre></body></html>

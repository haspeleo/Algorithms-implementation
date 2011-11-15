//<html><body><pre>

/*
 * Example ATM simulation - file window.h
 *
 * This file declares a window class on top of the curses package to provide
 * a simple, portable way of representing the ATM on text-based terminals
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include <curses.h>

class Window;

typedef Window & (*__wmanip)(Window &);

class Window
  {
    public:

        Window(int lines, int cols, int begin_y, int begin_x);

        // Output text into the window.  The text is not actually displayed
        // until the refresh manipulator is output.

        Window & operator << (char c);
        Window & operator << (const char * str);
        Window & operator << (__wmanip func)    { return (*func)(*this); }

        // Position cursor within window

        void putCursor(int y, int x);

        // Input text from the window.  The cursor is positioned just after
        // the last text output to the window, or at the start of the window
        // if no text has been output.

        Window & operator >> (char & c);
        Window & operator >> (char * str);
        Window & operator >> (__wmanip func)    { return (*func)(*this); }

        // Input a single key from the window, with no echoing and no delay.
        // If the parameter is non-NULL, then the key must be one of the 
        // characters occurring in that string, or the terminal bell
        // is rung and the function continues to wait for input.  If
        // the parameter is NULL, any key is accepted.

        char inkey(char * allowable = NULL);

        // Used only by the implementation routines

        WINDOW * Cwindow()              { return _Cwindow; }

        // Destructor
     
        ~Window();
     
   private:

        WINDOW * _Cwindow;
  };

// The following manipulators (respectively) clear the affected window and
// start writing at its beginning, (re)paint the window on the screen, 
// and output a warning bell for erroneous input.

extern  Window & clearW(Window & window);
extern  Window & refreshW(Window & window);
extern  Window & bell(Window & window);

// This subclass creates a window that is enclosed in a fancy box on the
// screen, with a legend near the upper left corner.  The area available for
// actual use is reduced by one line on the top and bottom and one character
// each side to allow for the box.

class BoxedWindow : public Window
  {
    public:

        BoxedWindow(char * legend,int lines,int cols, int begin_y, int begin_x);
  };

//</pre></body></html>

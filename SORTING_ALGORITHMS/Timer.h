/*
 * File:   Timer.h
 * Author: doghmen
 *
 * Created on 6 avril 2011, 00:18
 */

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <ctime>

class Timer {
public:
  typedef double diff_type;

  // Same as Timer t; t.begin();
  Timer(): start(std::clock()), elapsed(0) {}
  // Last result before a call to begin()
  diff_type last() const { return elapsed; }
  // Reset the timer
  void begin() { start = std::clock(); elapsed = 0; }
  // Save the result
  diff_type end();
private:
  std::clock_t start;
  diff_type    elapsed;
};

Timer::diff_type Timer::end()
{
  elapsed = (diff_type)std::clock() - start;
  elapsed /= CLOCKS_PER_SEC;
  return elapsed;
}

#endif // TIMER_H_INCLUDED



//#include <ctime>
//
//#ifndef TIMER_H
//#define	TIMER_H
//
//class Timer {
//public:
//    typedef double diff_type;
//    //Same as Timer t; t.begin();
//    Timer(): start(std::clock(), elapsed(0)) {}
//    //Last result before a call to begin()
//    diff_type end();
//
//private:
//    std::clock_t start;
//    diff_type elapsed;
//};
//
//Timer::diff_type Timer::end() {
//    elapsed  = (diff_type)std::clock() -start;
//    elapsed /= CLOCKS_PER_SEC;
//    return elapsed;
//}
//
//
//
//#endif	/* TIMER_H */

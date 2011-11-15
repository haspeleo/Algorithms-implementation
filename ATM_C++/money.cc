//<html><head><title>ATM Simulation - Implementation of a Representation for Money</title></head><body><h2>ATM Simulation - Implementation of a Representation for Money</h2><pre>



/*
 * Example ATM simulation - file money.cc
 *
 * This file implements the class used to represent money,
 * declared in money.h
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include "sysdep.h"
#include "money.h"

Money::Money()
  : _cents(0)
  { }

Money::Money(int dollars)
  : _cents(100L * dollars)
  { }

Money::Money(int dollars, long cents)
  : _cents(100L * dollars + cents)
  { }

Money Money::operator + (const Money & other) const
  { return Money(0, _cents + other._cents); }

Money Money::operator - (const Money & other) const
  { return Money(0, _cents - other._cents); }

Money & Money::operator += (const Money & other)
  { _cents += other._cents; 
    return * this;
  }

Money & Money::operator -= (const Money & other)
  { _cents -= other._cents; 
    return * this;
  }

int Money::dollars() const
  { return (int) _cents / 100; }

int Money::cents() const
  { return (int) _cents % 100; }


bool Money::operator == (const Money & other) const
  { return _cents == other._cents; }

bool Money::operator <  (const Money & other) const
  { return _cents <  other._cents; }


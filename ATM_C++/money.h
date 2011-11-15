//<html><head><title>ATM Simulation - Interface to a Representation for Money</title></head><body><h2>ATM Simulation - Interface to a Representation for Money</h2><pre>



/*
 * Example ATM simulation - file money.h
 *
 * This file declares the class used to represent money
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

//</pre><a name="Money"><hr><h3>Interface for class Money</h3><pre>

class Money
  {
    public:

        Money();                        // Initialize to 0.00
        Money(int dollars);             // Exact dollar amount - no cents
        Money(int dollars, long cents);

        Money operator +    (const Money & other) const;
        Money operator -    (const Money & other) const;
        Money & operator += (const Money & other);
        Money & operator -= (const Money & other);

        int dollars() const;
        int cents() const;

        // All other comparisons can be done in terms of these two
        // (actually just < is strictly needed!)
     
        bool operator == (const Money & other) const;
        bool operator <  (const Money & other) const;

    private:

        unsigned long _cents;
  };

//<html><head><title>ATM Simulation Interface - Individual Sessions</title></head><body><h2>ATM Simulation Interface - Individual Sessions</h2><pre>

/*
 * Example ATM simulation - file session.h
 *
 * This file declares the class that represents a single customer session
 * with the ATM, implementing the corresponding use case.
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

class Transaction;   // Session and Transaction refer mutually to one another,
                     // so one needs an incomplete declaration to start us off

//</pre><a name="Session"><hr><h3>Interface for class Session</h3><pre>

class Session
  {
    /* PURPOSE: Manage a session with a single user.
    */

    public:

        Session(int cardNumber, ATM & atm, Bank & bank);

        // Run session until user is through or some exceptional condition
        // prevents further processing

        void doSessionUseCase();

        // Force user to re-enter PIN if bank says original PIN was invalid.
        // Return final code from resubmission to bank.

        Status::Code doInvalidPINExtension();

        // Report a failed transaction to the user, and ask if he/she wants
        // to do another.
     
        bool doFailedTransactionExtension(Status::Code reason);
     
        // Each transation obtains this information from the session when it
        // is needed

        int cardNumber() const;
        int PIN() const;

    private:

        int                       _cardNumber;
        ATM &                     _atm;
        Bank &                    _bank;
        enum { RUNNING, FINISHED, ABORTED }
                                  _state;
        int                       _PIN;
        Transaction *             _currentTransaction;
  };

//</pre></body></html>

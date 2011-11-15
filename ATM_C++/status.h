//<html><head><title>ATM Simulation Status Codes</title></head><body><h2>ATM Simulation Status Codes</h2><pre>

/*
 * Example ATM simulation - file status.h
 *
 * This file declares a status code type that is returned by various
 * operations to indicate success or failure, and the reason for failure
 * 
 * Copyright (c) 1997 - Russell C. Bjork
 *
 */

//</pre><a name="Status"><hr><h3>class Status (no implementation needed)</h3><pre>

class Status
  {
    public:
   
        enum Code
          { 
            SUCCESS,
               
            // Cash dispenser does not have enough cash for a withdrawl request
            
            TOO_LITTLE_CASH,

            // Customer failed to deposit envelope in allowed time
               
            ENVELOPE_DEPOSIT_TIMED_OUT,
               
            // Various reasons why bank might reject a transaction
               
            UNKNOWN_CARD,    // Card number not recognized
            INVALID_PIN,     // PIN not correct for card
            NO_SUCH_ACCOUNT, // Card holder does not have this type account
            CANT_WITHDRAW_FROM_ACCOUNT,  // Account doesn't allow ATM withdrawl
            INSUFFICIENT_AVAILABLE_BALANCE, // Self-explanatory
            DAILY_WITHDRAWL_LIMIT_EXCEEDED  // Ditto
 
          };
  };

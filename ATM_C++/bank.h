//<html><head><title>ATM Simulation interface - the Bank</title></head><body><h2>ATM Simulation interface - the Bank</h2><pre>

/*
 * Example ATM simulation - file bank.h
 *
 * This file declares the class that manages communication with the bank
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */


class ATM; // Bank and ATM refer mutually to one another, so we need an
           // incomplete declaration to get us started

//</pre><a name="Bank"><hr><h3>Interface for class Bank</h3><pre>
class Bank
  {
    /* 
     *PURPOSE: Manage dialogue between the ATM and the bank
     */

    public:

        Bank();

        // The different types of account that can be linked to a card

        enum AccountType 
          { CHECKING, SAVINGS, MONEY_MARKET };

        // Withdrawls and deposits are done in two stages - first the 
        // transaction is approved, then the bank is notified as to whether
        // or not if was physically completed

        Status::Code initiateWithdrawl(int cardNumber,
                                       int PIN,
                                       int ATMnumber,
                                       int serialNumber,
                                       AccountType from,
                                       Money amount,
                                       Money & newBalance,
                                       Money & availableBalance);

        void          finishWithdrawl(int ATMnumber, 
                                      int serialNumber,
                                      bool succeeded);

        Status::Code   initiateDeposit(int cardNumber,
                                       int PIN,
                                       int ATMnumber,
                                       int serialNumber,
                                       AccountType to,
                                       Money amount,
                                       Money & newBalance,
                                       Money & availableBalance);

        void            finishDeposit(int ATMnumber, 
                                      int serialNumber,
                                      bool succeeded);

        // Each of these approves and does a transaction.  No notice of
        // physical completion is needed.

        Status::Code         doTransfer(int cardNumber,
                                        int PIN,
                                        int ATMnumber,
                                        int serialNumber,
                                        AccountType from,
                                        AccountType to,
                                        Money amount,
                                        Money & newBalance,
                                        Money & availableBalance);

        Status::Code         doInquiry(int cardNumber,
                                       int PIN,
                                       int ATMnumber,
                                       int serialNumber,
                                       AccountType from,
                                       Money & newBalance,
                                       Money & availableBalance);

        // Allow customer to choose an account type
     
        AccountType chooseAccountType(const char * purpose, ATM & atm);
     
        const char * accountName(AccountType type) const;

        const char * rejectionExplanation(Status::Code code) const;
  };


//</pre></body></html>

//<html><body><pre>

/*
 * Example ATM simulation - file bank.cc
 *
 * This file implements the class that manages communication with the bank,
 * as declared in bank.h
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include <string.h>

#include "sysdep.h"
#include "status.h"
#include "money.h"
#include "bank.h"
#include "session.h"
#include "transaction.h"
#include "atmparts.h"
#include "atm.h"

// A complete simulation of the bank is not needed for the purposes of this
// example.  The code below implements a very limited simulation having a few
// ATM cards and a handful of accounts.  Information about these is stored in
// variables (and is thus not preserved between runs of the program), and is
// initialized to "hardwired" constant values at startup.  We disallow
// ATM withdrawls/transfers from SAVINGS.

// A more realistic implementation is left as an exercise to the student!

#define NUMBER_CARDS    2
#define NUMBER_ACCOUNTS 3

// PIN for each card:

static int _PIN [ NUMBER_CARDS + 1 ] = 
  { 0, // dummy for nonexistent card 0
    42, 1234 
  };

// Total withdrawls so far today using each card

static Money _withdrawlsToday  [ NUMBER_CARDS + 1] =
  { Money(0),   //dummy for nonexistent card 0
    Money(0),
    Money(0)
  };

#define MAXIMUM_WITHDRAWL_AMOUNT_PER_DAY Money(300)

// Accounts (CHECKING, SAVINGS, MONEY_MARKET) linked to each card - 0 = none

static int _accountNumber [ NUMBER_CARDS + 1 ] [ 3 ] =
  { { 0, 0, 0 }, // dummies for nonexistent card 0
    { 1, 2, 0 },
    { 1, 0, 3 }
  };

// Current and available balances of each account

static Money _currentBalance   [ NUMBER_ACCOUNTS + 1 ] =
  { Money(0), // dummy for nonexistent account 0
    Money(100), 
    Money(1000),
    Money(5000) 
  }; 

static Money _availableBalance [ NUMBER_ACCOUNTS + 1 ] =
  { Money(0), // dummy for nonexistent account 0
    Money(100), 
    Money(1000),
    Money(5000) 
  }; 

// A real system would use the transaction commit/rollback mechanisms of an 
// underlying DBMS - we just save the most recent transaction initiated in
// a variable and complete if when we get the finish call.

static int _currentTransactionCard;
static int _currentTransactionAccount;
static Money _currentTransactionAmount;

Bank::Bank()
  { }

Status::Code Bank::initiateWithdrawl(int cardNumber,
                                     int PIN,
                                     int ATMnumber,
                                     int serialNumber,
                                     AccountType from,
                                     Money amount,
                                     Money & newBalance,
                                     Money & availableBalance)
  { 
    if (cardNumber < 1 || cardNumber > NUMBER_ACCOUNTS)
        return Status::UNKNOWN_CARD;

    if (PIN != _PIN [ cardNumber ] )
        return Status::INVALID_PIN;

    _currentTransactionCard = cardNumber;
    _currentTransactionAccount = _accountNumber [ cardNumber ] [ from ];
    if (_currentTransactionAccount == 0)
        return Status::NO_SUCH_ACCOUNT;

    if (from == SAVINGS)
        return Status::CANT_WITHDRAW_FROM_ACCOUNT;

    if (_availableBalance [ _currentTransactionAccount ] < amount)
        return Status::INSUFFICIENT_AVAILABLE_BALANCE;

    if (MAXIMUM_WITHDRAWL_AMOUNT_PER_DAY <
             _withdrawlsToday [ cardNumber ] + amount)
        return Status::DAILY_WITHDRAWL_LIMIT_EXCEEDED;

    _currentTransactionAmount = amount;
    newBalance = _currentBalance [ _currentTransactionAccount ] - amount;
    availableBalance = _availableBalance [_currentTransactionAccount] - amount;

    return Status::SUCCESS;
  }

void Bank::finishWithdrawl(int ATMnumber,
                           int serialNumber, 
                           bool succeeded)
  { 
    if (succeeded)
      { _withdrawlsToday [ _currentTransactionCard ] +=
                _currentTransactionAmount;
        _currentBalance [ _currentTransactionAccount ] -= 
                _currentTransactionAmount;
        _availableBalance [ _currentTransactionAccount ] -=
                _currentTransactionAmount;
      }
  }


Status::Code Bank::initiateDeposit(int cardNumber,
                                   int PIN,
                                   int ATMnumber,
                                   int serialNumber,
                                   AccountType to,
                                   Money amount,
                                   Money & newBalance,
                                   Money & availableBalance)
  { 
    if (cardNumber < 1 || cardNumber > NUMBER_ACCOUNTS)
        return Status::UNKNOWN_CARD;

    if (PIN != _PIN[cardNumber])
        return Status::INVALID_PIN;

    _currentTransactionCard = cardNumber;
    _currentTransactionAccount = _accountNumber [ cardNumber ] [ to ];
    if (_currentTransactionAccount == 0)
        return Status::NO_SUCH_ACCOUNT;

    _currentTransactionAmount = amount;
    newBalance = _currentBalance [ _currentTransactionAccount ] + amount;
    availableBalance = _availableBalance[ _currentTransactionAccount ];
    return Status::SUCCESS;
  }


void Bank::finishDeposit(int ATMnumber,
                         int serialNumber, 
                         bool succeeded)
  {
    if (succeeded)
        _currentBalance [ _currentTransactionAccount ] +=
                _currentTransactionAmount;
  }

Status::Code Bank::doTransfer(int cardNumber,
                              int PIN,
                              int ATMnumber,
                              int serialNumber,
                              AccountType from,
                              AccountType to,
                              Money amount,
                              Money & newBalance,
                              Money & availableBalance)
  { 
    if (cardNumber < 1 || cardNumber > NUMBER_ACCOUNTS)
        return Status::UNKNOWN_CARD;

    if (PIN != _PIN [ cardNumber ])
        return Status::INVALID_PIN;

    int fromAccount = _accountNumber [ cardNumber ] [ from ],
               toAccount = _accountNumber [ cardNumber ] [ to ];
    if (fromAccount == 0 || toAccount == 0)
        return Status::NO_SUCH_ACCOUNT;

    if (from == SAVINGS)
        return Status::CANT_WITHDRAW_FROM_ACCOUNT;

    if (_availableBalance [ fromAccount ] < amount)
        return Status::INSUFFICIENT_AVAILABLE_BALANCE;

    _currentBalance [ fromAccount ]   -= amount;
    _currentBalance [ toAccount ]     += amount;
    _availableBalance [ fromAccount ] -= amount;
    _availableBalance [ toAccount ]   += amount;

    newBalance = _currentBalance [ toAccount ];
    availableBalance = _availableBalance [ toAccount ];

    return Status::SUCCESS;
  }


Status::Code Bank::doInquiry(int cardNumber,
                             int PIN,
                             int ATMnumber,
                             int serialNumber,
                             AccountType from,
                             Money & newBalance,
                             Money & availableBalance)
  {
    if (cardNumber < 1 || cardNumber > NUMBER_ACCOUNTS)
        return Status::UNKNOWN_CARD;

    if (PIN != _PIN [ cardNumber ] )
        return Status::INVALID_PIN;

    int account = _accountNumber [ cardNumber ] [ from ];
    if (account == 0)
        return Status::NO_SUCH_ACCOUNT;

    newBalance = _currentBalance [ account ];
    availableBalance = _availableBalance [ account ];

    return Status::SUCCESS;
  }

Bank::AccountType Bank::chooseAccountType(const char * purpose, ATM & atm)
  { const char * menu[] = { "Checking", "Savings", "Money Market" };
    const char * prologue = "Please choose an account to ";
    char * description = new char[strlen(prologue) + strlen(purpose) + 1];
    strcpy(description, prologue);
    strcat(description, purpose);
    int choice = atm.getMenuChoice(description, 3, menu);
    delete [] description;
    return AccountType(choice - 1);
  }

const char * Bank::accountName(AccountType type) const
  { static const char * accountNames[3] = 
        { "CHKNG ", "SVNGS ", "MNYMKT" };
    return accountNames[type];
  }
        
const char * Bank::rejectionExplanation(Status::Code code) const
  { static const char * explanation[] = 
      { 
        "Your card number was not recognized",
        "Invalid PIN",
        "No account of the type you requested is linked to your card",
        "You cannot withdraw money from this type of account at an ATM",
        "The available balance in your account is not sufficient",
        "You have exceeded the daily limit on cash withdrawls with your card" 
      };
    return explanation[code - Status::UNKNOWN_CARD];
  }

//</pre></body></html>

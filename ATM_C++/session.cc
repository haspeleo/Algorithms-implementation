// <html><head><title>ATM Simulation Implementation - Individual Sessions</title></head><body><h2>ATM Simulation Implementation - Individual Sessions</h2><pre>

/*
 * Example ATM simulation - file session.cc
 *
 * This file implements the class that represents a single customer session
 * with the ATM, declared in session.h
 *
 * Copyright (c) 1996,1997 - Russell C. Bjork
 *
 */

#include "sysdep.h"
#include "status.h"
#include "money.h"
#include "bank.h"
#include "session.h"
#include "transaction.h"
#include "atmparts.h"
#include "atm.h"


//</pre><a name="Session::Session"><hr><pre>

Session::Session(int cardNumber, ATM & atm, Bank & bank)
  : _cardNumber(cardNumber),
    _atm(atm),
    _bank(bank),
    _state(RUNNING),
    _PIN(0),
    _currentTransaction(NULL)
  { }


//</pre><a name="Session::doSessionUseCase"><hr><pre>

void Session::doSessionUseCase()
  {
    _PIN = _atm.getPIN();
    
    do
      {
        const char * anotherMenu[] = { "Yes", "No" };
        _currentTransaction = Transaction::chooseTransaction(*this,_atm,_bank);
        Status::Code status = _currentTransaction -> doTransactionUseCase();
        switch (status)
          {
            case Status::SUCCESS:

              if (1 != _atm.getMenuChoice
                ("Do you want to perform another transaction?",2,anotherMenu))
                  _state = FINISHED;
              break;
            
            case Status::INVALID_PIN:
             
              _state = ABORTED;
              break;
             
           default:
             
             bool doAnother = doFailedTransactionExtension(status);
             if (! doAnother)
               _state = FINISHED;
          }
             
        delete _currentTransaction;
      }
    while (_state == RUNNING);

    if (_state != ABORTED) 
        _atm.ejectCard();
  }


//</pre><a name="Session::doInvalidPINExtension"><hr><pre>

Status::Code Session::doInvalidPINExtension()
  { 
    Status::Code code;
    for (int i = 0; i < 3; i ++)
      { _PIN = _atm.reEnterPIN();
        code = _currentTransaction -> sendToBank();     
        if (code != Status::INVALID_PIN)
            return code;
      }
    _atm.retainCard();
    _state = ABORTED;
    return Status::INVALID_PIN;
  }


//</pre><a name="Session:doFailedTransactionExtension"><hr><pre>

bool Session::doFailedTransactionExtension(Status::Code reason)
  { switch(reason)
      { 
        case Status::TOO_LITTLE_CASH:

            return _atm.reportTransactionFailure(
         "Sorry, there is not enough cash available to satisfy your request");

        case Status::ENVELOPE_DEPOSIT_TIMED_OUT:

            return _atm.reportTransactionFailure(
         "Envelope not deposited - transaction cancelled");
         
        default:

            return _atm.reportTransactionFailure(
         _bank.rejectionExplanation(reason));

      } 
  }


//</pre><a name="Session::cardNumber"><hr><pre>

int Session::cardNumber() const
  { return _cardNumber; }


//</pre><a name="Session::PIN"><hr><pre>

int Session::PIN() const
  { return _PIN; }

//</pre></body></html>

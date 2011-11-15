//<html><body><pre>

/*
 * Example ATM simulation - file atmparts.cc
 *
 * This file implements the classes that manage the ATM's components
 * - as declared in atmparts.h
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include <string.h>
#ifndef VMS
#include <unistd.h>
#else
#include <signal.h>
#endif
#include <stdio.h>
#include <time.h>

#include "sysdep.h"
#include "status.h"
#include "money.h"
#include "bank.h"
#include "session.h"
#include "transaction.h"
#include "atmparts.h"
#include "atm.h"

// A large part of the responsibility of the classes implemented in this file
// concerns the user interface.  This particular implementation is designed
// for use on a standard 24 x 80 text-based terminal, and uses the Curses 
// package to manage windows that simulate the various components  The class 
// Window (built on top of the Curses package) will manage these for us.  To 
// avoid putting the details of this in the class interface, we declare a static
// Window here for each component of the ATM.  

// The interface to class Window is in file window.h

#include "window.h"

// Widths and heights below must allow room for drawing a box around the
// window - one line at top, one at bottom, one char at left and one at right

/*
 * Arrangement:                 --------- DISPLAY ----------
 *                              CASH      CARD       RECEIPT
 *                               "       ENVELOPE       "
 *                              ---miscellaneous (no box)---
 *
 */

#define DISPLAY_WINDOW_HEIGHT   10
#define DISPLAY_WINDOW_WIDTH    80
#define DISPLAY_WINDOW_TOP      0
#define DISPLAY_WINDOW_LEFT     0

#define CASH_WINDOW_HEIGHT      9
#define CASH_WINDOW_WIDTH       23
#define CASH_WINDOW_TOP         (DISPLAY_WINDOW_TOP + DISPLAY_WINDOW_HEIGHT)
#define CASH_WINDOW_LEFT        0

#define CARD_WINDOW_HEIGHT      5
#define CARD_WINDOW_WIDTH       28
#define CARD_WINDOW_TOP         (DISPLAY_WINDOW_TOP + DISPLAY_WINDOW_HEIGHT)
#define CARD_WINDOW_LEFT        (CASH_WINDOW_LEFT + CASH_WINDOW_WIDTH)

#define ENVELOPE_WINDOW_HEIGHT  4
#define ENVELOPE_WINDOW_WIDTH   28
#define ENVELOPE_WINDOW_TOP     (CARD_WINDOW_TOP + CARD_WINDOW_HEIGHT)
#define ENVELOPE_WINDOW_LEFT    (CASH_WINDOW_LEFT + CASH_WINDOW_WIDTH)

#define RECEIPT_WINDOW_HEIGHT   9
#define RECEIPT_WINDOW_WIDTH    29
#define RECEIPT_WINDOW_TOP      (DISPLAY_WINDOW_TOP + DISPLAY_WINDOW_HEIGHT)
#define RECEIPT_WINDOW_LEFT     (CARD_WINDOW_LEFT + CARD_WINDOW_WIDTH)

#define MISC_WINDOW_HEIGHT      2
#define MISC_WINDOW_WIDTH       80
#define MISC_WINDOW_TOP         (CASH_WINDOW_TOP + CASH_WINDOW_HEIGHT)
#define MISC_WINDOW_LEFT        0

static BoxedWindow      _displayWindow("DISPLAY",
                                        DISPLAY_WINDOW_HEIGHT, 
                                        DISPLAY_WINDOW_WIDTH,
                                        DISPLAY_WINDOW_TOP,
                                        DISPLAY_WINDOW_LEFT),

                        _cashWindow("CASH DISPENSER",
                                     CASH_WINDOW_HEIGHT,
                                     CASH_WINDOW_WIDTH,
                                     CASH_WINDOW_TOP,
                                     CASH_WINDOW_LEFT),

                        _cardWindow("CARD SLOT",
                                    CARD_WINDOW_HEIGHT,
                                    CARD_WINDOW_WIDTH,
                                    CARD_WINDOW_TOP,
                                    CARD_WINDOW_LEFT),

                        _envelopeWindow("ENVELOPE SLOT",
                                        ENVELOPE_WINDOW_HEIGHT,
                                        ENVELOPE_WINDOW_WIDTH,
                                        ENVELOPE_WINDOW_TOP,
                                        ENVELOPE_WINDOW_LEFT),

                        _receiptWindow("RECEIPT",
                                        RECEIPT_WINDOW_HEIGHT,
                                        RECEIPT_WINDOW_WIDTH,
                                        RECEIPT_WINDOW_TOP,
                                        RECEIPT_WINDOW_LEFT);

static Window           _miscWindow(MISC_WINDOW_HEIGHT,
                                    MISC_WINDOW_WIDTH,
                                    MISC_WINDOW_TOP,
                                    MISC_WINDOW_LEFT);

// The operator switch and the card reader insertion test make use of the
// _miscWindow.  The user types a C in this window to insert a card, and an
// S to toggle the switch.  The following variable holds one of three
// values: ' ' - no prompt yet displayed, no value read; 'C'/'c' or 'S'/'s' - 
// one of these has been read

static char _miscWindowInput = ' ';

CardReader::CardReader()
  : _status(NO_CARD)
  { }

CardReader::ReaderStatus CardReader::checkForCardInserted()
  { 
    if (_status != NO_CARD)
        return _status;

    if (_miscWindowInput == ' ')
      {
        _miscWindow << clearW 
                    << "Type C to insert card, S to toggle operator switch "
                    << refreshW;
        _miscWindowInput = _miscWindow.inkey("CcSs");
      }

    if (_miscWindowInput == 'C' || _miscWindowInput == 'c')
      { _miscWindowInput = ' ';
        _miscWindow << clearW << refreshW;
        _cardWindow << "Card number: ";
        char cardNumberString[20];
        _cardWindow >> cardNumberString;
        if (sscanf(cardNumberString, "%d", & _cardNumberRead) == 1)
            _status = CARD_HAS_BEEN_READ;
        else
            _status = UNREADABLE_CARD;
        _cardWindow << clearW << refreshW;
        return _status;
      }
    else
        return NO_CARD;
  }

int CardReader::cardNumber() const
  { return _cardNumberRead; }

void CardReader::ejectCard()
  { _status = NO_CARD; 
    int i;
    for (i = 2; i >= 0; i --)
      { _cardWindow.putCursor(i, 0);
        _cardWindow << "    EJECTING CARD" << refreshW;
        sleep(1);
       }
    for (i = 2; i >= 0; i --)
      { _cardWindow.putCursor(i, 0);
        _cardWindow << "                 " << refreshW;
        sleep(1);
      }
    _cardWindow << clearW << refreshW;
  }

void CardReader::retainCard()
  { _status = NO_CARD; }

Display::Display()
  { }

void Display::requestCard()
  { _displayWindow << clearW << 
        " Please insert your card to begin" <<
     refreshW;
  }

void Display::requestPIN()
  { _displayWindow << clearW << 
        " Please enter your Personal Identification Number (PIN)\n"
        " Press ENTER when finished or DELETE to start over" <<
     refreshW;
  }
     
void Display::displayMenu(const char * whatToChoose,
                          int numItems,
                          const char * items[])
  { _displayWindow << clearW << " " << whatToChoose;
    int menuLinesAvailable = DISPLAY_WINDOW_HEIGHT - 2 - 2;
    int itemsPerLine = 1 + (numItems - 1) / menuLinesAvailable;
    int menuColsPerItem = (DISPLAY_WINDOW_WIDTH - 2) / itemsPerLine;
    for (int i = 0; i < menuLinesAvailable; i ++)
      { int row = i + 2;
        int col = 0;
        for (int j = i; j < numItems; j += menuLinesAvailable)
          { _displayWindow.putCursor(row, col);
            _displayWindow << " " << ((char) j) + '1' << ") " << items[j];
            col += menuColsPerItem;
          }
      }
    _displayWindow << refreshW;
  }


void Display::requestAmountEntry()
  { _displayWindow << clearW << 
        " Please enter amount."
        " Press ENTER when finished or DELETE to start over" <<
     refreshW;
  }

void Display::requestDepositEnvelope()
  { _displayWindow << clearW << 
        " Please deposit an envelope in the slot" <<
     refreshW;
  }

void Display::reportCardUnreadable()
  { _displayWindow << clearW << 
        " Sorry, your card was inserted incorrectly or is unreadable.\n"
        " Please try inserting your card again" <<
     refreshW;
  }

void Display::reportTransactionFailure(const char * explanation)
  { _displayWindow << clearW << 
        " " <<  explanation << "\n\n" <<
        " Do you want to perform another transaction (1 = Yes, 2 = No)?" <<
    refreshW;
  }

void Display::requestReEnterPIN()
  { _displayWindow << clearW << 
        " Your PIN was entered incorrectly.\n"
        " Please re-enter it" <<
     refreshW;
  }

void Display::reportCardRetained()
  { _displayWindow << clearW << 
        " Your PIN was entered incorrectly.\n"
        " Your card has been retained - please contact the bank" <<
    refreshW;
    sleep(20);
  }

void Display::echoInput(const char * echo)
  { _displayWindow.putCursor(DISPLAY_WINDOW_HEIGHT - 2 - 1, 0);
    _displayWindow << ' ' << echo;
    for (int i = strlen(echo) + 1; i < DISPLAY_WINDOW_WIDTH - 2; i ++)
        _displayWindow << ' ';
    _displayWindow.putCursor(DISPLAY_WINDOW_HEIGHT - 2 - 1, strlen(echo) + 1);
    _displayWindow << refreshW;
  }

void Display::clearDisplay()
  { _displayWindow << clearW << refreshW;
  }

Keyboard::Keyboard()
  { }

// Note that the keyboard uses the miscellaneous window to read from - since
// nothing is actually echoed during the read.  Echoing is done by calling 
// Display::echoInput

int Keyboard::readPIN(Display & echoOn)
  { 
    char PINstring[20], echoString[20];
    int i;
    for (i = 0; i < 19; )
      { echoString[i] = '\0';
        echoOn.echoInput(echoString);
        char c = _miscWindow.inkey("0123456789\177\r");
        if (c == '\177')
            i = 0;
        else if (c == '\r' && i > 0)
            break;
        else if (c == '\r')
            _miscWindow << bell;
        else
          { PINstring[i] = c;
            echoString[i ++] = '*';
          }
      }
    PINstring[i] = '\0';
    int PIN;
    sscanf(PINstring, "%d", & PIN);
    return PIN;
  }

int Keyboard::readMenuChoice(int numItems)
  {
    char valid[256];
    for (int i = 0; i < numItems; i ++)
       valid[i] = (char) (i + '1');
    valid[numItems] = '\0';
    return (int) _miscWindow.inkey(valid) - '0';
  }


Money Keyboard::readAmountEntry(Display & echoOn)
  { 
    char dollarString[17], centString[3];
    int dollars, cents;
    bool done = false;
    do
      { strcpy(dollarString, "                ");
        strcpy(centString, "  ");
        while (dollarString[0] == ' ' && ! done)
          { char echoString[22];
            sprintf(echoString, "%s.%s", dollarString, centString);
            echoOn.echoInput(echoString);
            char c = _miscWindow.inkey("0123456789\177\r");
            if (c == '\177')
                break;
            else if (c == '\r' && centString[1] != ' ')
                done = true;
            else if (c == '\r')
                _miscWindow << bell;
            else
              { strncpy(dollarString, dollarString + 1, 15);
                dollarString[15] = centString[0];
                dollarString[16] = '\0';
                centString[0] = centString[1];
                centString[1] = c;
              }
          }
      }
    while (! done);

    if (dollarString[15] != ' ')
        sscanf(dollarString, "%d", & dollars);
    else
        dollars = 0;
    sscanf(centString, "%d", & cents);
    return Money(dollars, cents);
  }

CashDispenser::CashDispenser()
  : _currentCash(0)
  { }

void CashDispenser::setCash(Money initialCash)
  { _currentCash = initialCash; }

void CashDispenser::dispenseCash(Money amount)
  { char amountString[10];
    sprintf(amountString, "%d.%02d", amount.dollars(), amount.cents());
    _cashWindow << clearW << refreshW;
    for (int i = CASH_WINDOW_HEIGHT - 3; i >= 0; i --)
      { _cashWindow << clearW;
        _cashWindow.putCursor(i,0);
        _cashWindow << "Dispensing $" << amountString << refreshW;
        sleep(1);
      }
    _cashWindow << clearW << refreshW;
    _currentCash -= amount;
  }

Money CashDispenser::currentCash() const
  { return _currentCash; }

EnvelopeAcceptor::EnvelopeAcceptor()
  { }

bool EnvelopeAcceptor::acceptEnvelope()
  { _envelopeWindow << clearW << "Press E to enter envelope\nT to time-out" 
                    << refreshW;
    char choice = _envelopeWindow.inkey("EeTt");
    _envelopeWindow << clearW << refreshW;
    return choice == 'E' || choice == 'e';
  }

ReceiptPrinter::ReceiptPrinter()
  { }

void ReceiptPrinter::printReceipt(int theATMnumber,
                                  const char * theATMlocation,
                                  int cardNumber,
                                  int serialNumber,
                                  const char * description,
                                  Money amount,
                                  Money balance,
                                  Money availableBalance)
  {
    // Set up the receipt

    // Width of line allows for full line of text + newline + null
    char receiptLine[7][RECEIPT_WINDOW_WIDTH - 2 + 2];
    time_t now = time(NULL);
    sprintf(receiptLine[0], ctime(& now));
    sprintf(receiptLine[1], "#%4d %s\n", theATMnumber, theATMlocation);
    sprintf(receiptLine[2], "CARD %7d TRANS %7d\n", cardNumber, serialNumber);
    sprintf(receiptLine[3], "%s\n", description);
    if (amount == Money(0))
        sprintf(receiptLine[4], "\n");
    else
        sprintf(receiptLine[4], "AMOUNT:    %12d.%02d\n",
                amount.dollars(), amount.cents());
    sprintf(receiptLine[5], "CURR BAL:  %12d.%02d\n",
        balance.dollars(), balance.cents());
    sprintf(receiptLine[6], "AVAILABLE: %12d.%02d\n", 
        availableBalance.dollars(), availableBalance.cents());

    // Animate it

    _receiptWindow << clearW << refreshW;
    for (int i = 6; i >= 0; i --)
      { _receiptWindow << clearW;
        _receiptWindow.putCursor(i, 0);
        for (int j = 0; i + j <= 6; j ++)
            _receiptWindow << receiptLine[j];
        _receiptWindow << refreshW;
        sleep(1);
      }
    sleep(5);
    _receiptWindow << clearW << refreshW;
  }

OperatorPanel::OperatorPanel()
  { }

bool OperatorPanel::switchOn()
  { 
    // An actual switch is a mechanical device that can be moved from one
    // state to another.  We will simulate this with a static variable that
    // can be toggled by the user typing "S"

    static bool isOn = false;

    if (_miscWindowInput == ' ' && ! isOn)
      {
        _miscWindow << clearW 
                    << "Type S to toggle operator switch "
                    << refreshW;
        _miscWindowInput = _miscWindow.inkey("Ss");
      }

    if (_miscWindowInput == 'S' || _miscWindowInput == 's')
      { _miscWindowInput = ' ';
        _miscWindow << clearW << refreshW;
        isOn = ! isOn;
      }

    return isOn;

  }

Money OperatorPanel::getInitialCash()
  { 
    char numBillsString[100];
    int numBills = -1;

    do
      {
        _miscWindow << clearW
                    << "How many $20 bills are in the cash dispenser? "
                    << refreshW;
        _miscWindow >> numBillsString;
        if (sscanf(numBillsString, "%d", & numBills)  != 1 || numBills < 0)
            _miscWindow << bell;
      }
    while (numBills < 0);

    return Money((20 * numBills));
  }

//</pre></body></html>

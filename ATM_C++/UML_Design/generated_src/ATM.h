#ifndef ATM_h
#define ATM_h

#include "CardReader.h"
#include "CashDispenser.h"
#include "CustomerConsole.h"
#include "EnvelopeAcceptor.h"
#include "NetworkToBank.h"
#include "OperatorPanel.h"
#include "ReceiptPrinter.h"

class Session;

class ATM {

 public:

    OperatorPanel myOperatorPanel;

    CardReader myCardReader;

    /**
     * @element-type Session
     */
    Session *mySession;


    /**
     * @element-type EnvelopeAcceptor
     */
    EnvelopeAcceptor *myEnvelopeAcceptor;

    /**
     * @element-type CashDispenser
     */
    CashDispenser *myCashDispenser;

    /**
     * @element-type ReceiptPrinter
     */
    ReceiptPrinter myReceiptPrinter;

    NetworkToBank myNetworkToBank;

    /**
     * @element-type CashDispenser
     */
    CashDispenser myCashDispenser;


    CustomerConsole myCustomerConsole;

    /**
     * @element-type Session
     */
    Session *mySession;

    /**
     * @element-type EnvelopeAcceptor
     */
    EnvelopeAcceptor myEnvelopeAcceptor;
};

#endif // ATM_h

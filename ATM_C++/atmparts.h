//<html><head><title>ATM Simulation Interface - ATM components</title></head><body><h2>ATM Simulation Interface - ATM components</h2><pre>

/*
 * Example ATM simulation - file atmparts.h
 *
 * This file declares the classes that manage the ATM's components
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

//</pre><a name="CardReader"><hr><h3>Interface for class CardReader</h3><pre>
class CardReader
  {
    /* 
     * PURPOSE: Model the ATM component that reads a customer's card
     */

    public:

        CardReader();

        void ejectCard();
        void retainCard();

        enum ReaderStatus 
          { NO_CARD, UNREADABLE_CARD, CARD_HAS_BEEN_READ };

        ReaderStatus checkForCardInserted();
        int cardNumber() const;

    private:

        ReaderStatus    _status;
        int             _cardNumberRead;        
  };

//</pre><a name="Display"><hr><h3>Interface for class Display</h3><pre>
class Display
  {
    /* 
     * PURPOSE: Model the ATM component that displays messages for the customer
     */

    public:

        Display();

        // The following display screens calling for the customer to take a
        // specific action
     
        void requestCard();
        void requestPIN();
        void displayMenu(const char * whatToChoose,
                         int numItems,
                         const char * items[]);
        void requestAmountEntry();
        void requestDepositEnvelope();
     
        // The following displays a screen reporting the customer's card
        // is unreadable
     
        void reportCardUnreadable();
    
        // The following displays a screen reporting why a transaction
        // failed, and asking if customer wants another.
      
        void reportTransactionFailure(const char * explanation);

        // The following are used in case the customer's PIN was incorrect
     
        void requestReEnterPIN();
        void reportCardRetained();

       // The following is used by the Keyboard to echo input as typed

       void echoInput(const char * echo);

       // Clear off the screen after a display has been seen

        void clearDisplay();
  };

//</pre><a name="Keyboard"><hr><h3>Interface for class Keyboard</h3><pre>
class Keyboard
  {
    /* 
     * PURPOSE: Model the ATM component that accepts input from the customer
     */

    public:

        Keyboard();

        int readPIN(Display & echoOn);
        int readMenuChoice(int numItems);
        Money readAmountEntry(Display & echoOn);
  };

//</pre><a name="CashDispenser"><hr><h3>Interface for class CashDispenser</h3><pre>
class CashDispenser
  {
    /* 
     * PURPOSE: Model the ATM component that dispenses cash during withdrawls
     */

    public:

        CashDispenser();

        void setCash(Money initialCash);
        void dispenseCash(Money amount);
        Money currentCash() const;

    private:

        Money _currentCash;
  };

//</pre><a name="EnvelopeAcceptor"><hr><h3>Interface for class EnvelopeAcceptor</h3><pre>
class EnvelopeAcceptor
  {
    /* 
     * PURPOSE: Model the ATM component that accepts an envelope during deposits
     */

    public:

        EnvelopeAcceptor();

        bool acceptEnvelope();
  };

//</pre><a name="ReceiptPrinter"><hr><h3>Interface for class ReceiptPrinter</h3><pre>
class ReceiptPrinter
  {
    /* 
     * PURPOSE: Model the ATM component that prints receipts
     */

    public:

        ReceiptPrinter();

        void printReceipt(int theATMnumber,
                          const char * theATMlocation,
                          int cardNumber,
                          int serialNumber,
                          const char * description,
                          Money amount,
                          Money balance,
                          Money availableBalance);
  };

//</pre><a name="OperatorPanel"><hr><h3>Interface for class OperatorPanel</h3><pre>
class OperatorPanel
  {
    /* 
     * PURPOSE: Model the ATM component that allows an operator to stop
     *          the machine for maintenance
     */

    public:

        OperatorPanel();

        bool switchOn();                // True iff "on"
        Money getInitialCash();
  };

//</pre></body></html>

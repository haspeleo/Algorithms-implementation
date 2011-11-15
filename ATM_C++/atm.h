//<html><head><title>ATM Simulation Interface - the ATM itself</title></head><body><h2>ATM Simulation Interface - the ATM itself</h2><pre>

/*
 * Example ATM simulation - file atm.h
 *
 * This file declares the class that represents the ATM itself
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

//</pre><a name="ATM"><hr><h3>Interface for class ATM</h3><pre>
class ATM
  {
    /* 
     * PURPOSE: Manage the overall ATM and its component parts
     */

    public:

        ATM(int number, const char * location, Bank & bank);

        // Start up operation

        Money startupOperation();

        // Run the ATM, servicing customers, until the switch is turned off

        void serviceCustomers(Money initialCash);

        // Interact with the customer in support of various use cases

        int getPIN() const;
        int getMenuChoice(const char * whatToChoose,
                          int numItems,
                          const char * items[]) const;
        Money getAmountEntry() const;           // From keyboard - any amount
        bool checkIfCashAvailable(Money amount) const;
        void dispenseCash(Money amount) const;
        bool acceptEnvelope() const;            // True iff success
        void issueReceipt(int cardNumber,
                          int serialNumber,
                          const char * description,
                          Money amount,
                          Money balance,
                          Money availableBalance) const;
        int reEnterPIN() const;
        bool reportTransactionFailure(const char * explanation) const;
        void ejectCard() const;
        void retainCard() const;
        
        int number() const;

    private:

        int                     _number;
        const char *            _location;
        Bank &                  _bank;
     
        enum {RUNNING, STOPPED} _state;

        CardReader &            _cardReader;
        Display &               _display;
        Keyboard &              _keyboard;
        CashDispenser &         _cashDispenser;
        EnvelopeAcceptor&       _envelopeAcceptor;
        ReceiptPrinter &        _receiptPrinter;
        OperatorPanel &         _operatorPanel;
  };


//</pre></body></html>

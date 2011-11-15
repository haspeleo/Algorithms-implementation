//<html><head><title>ATM Simulation Interface - Individual Transactions</title></head><body><h2>ATM Simulation Interface - Individual Transactions</h2><pre>
/*
 * Example ATM simulation - file transaction.h
 *
 * This file declares the classes that represent the various kinds of
 * transactions that the ATM can perform.  The class Transaction serves as
 * an abstract base class for the other classes.  Each concrete class
 * basically serves to implement the corresponding use case.
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */


//</pre><a name="Transaction"><hr><h3>Interface for class Transaction</h3><pre>
class Transaction
  {
    /*
     * PURPOSE: Serve as base class for specific types of transactions
     */

    public:

        Transaction(Session & session, ATM & atm, Bank & bank);

        // Ask the user to choose a transaction type, and create a transaction
        // object of the type, acting on behalf of the specified Session,
        // and communicating with the specified ATM and Bank

        static Transaction * chooseTransaction(Session & session,
                                               ATM & atm,
                                               Bank & bank);

        // Perform a particular transaction use case.  The card number and
        // PIN are obtained from the session; other information is obtained
        // from the customer.  The returned Status indicates whether the
        // transaction succeeded or failed, and if it failed, why

        Status::Code doTransactionUseCase();

        // Individual steps in carrying out a transaction.  Each must be
        // implemented individually for each type of transaction.  If
        // either of the first two steps returns in failure, the transaction 
        // is aborted.

        virtual Status::Code getTransactionSpecificsFromCustomer() = 0;
        virtual Status::Code sendToBank() = 0;
        virtual Status::Code finishApprovedTransaction() = 0;

    protected:

        // Session that created the transaction; ATM it uses to interact
        // with customer; Bank it communicates with to perform the job
     
        Session &       _session;
        ATM &           _atm;
        Bank &          _bank;
     
        // Every transaction is assigned a unique serial number that is used
        // to identify it in communications with the bank and on the receipt.

        int             _serialNumber;

        // Every transaction gets both the updated balance and available
        // balance for printing on the receipt.

        Money           _newBalance,
                        _availableBalance;

    private:

        static int      _lastSerialNumberAssigned;
  };

//</pre><a name="WithdrawlTransaction"><hr><h3>Interface for class WithdrawlTransaction</h3><pre>
class WithdrawlTransaction : public Transaction
  {
    public:

        WithdrawlTransaction(Session & session, ATM & atm, Bank & bank);

        Status::Code getTransactionSpecificsFromCustomer();
        Status::Code sendToBank();
        Status::Code finishApprovedTransaction();

    private:

        Bank::AccountType       _fromAccount;
        Money                   _amount;
  };

//</pre><a name="DepositTransaction"><hr><h3>Interface for class DepositTransaction</h3><pre>
class DepositTransaction : public Transaction
  {
    public:

        DepositTransaction(Session & session, ATM & atm, Bank & bank);

        Status::Code getTransactionSpecificsFromCustomer();
        Status::Code sendToBank();
        Status::Code finishApprovedTransaction();

    private:

        Bank::AccountType       _toAccount;
        Money                   _amount;
  };

//</pre><a name="TransferTransaction"><hr><h3>Interface for class TransferTransaction</h3><pre>
class TransferTransaction : public Transaction
  {
    public:

        TransferTransaction(Session & session, ATM & atm, Bank & bank);

        Status::Code getTransactionSpecificsFromCustomer();
        Status::Code sendToBank();
        Status::Code finishApprovedTransaction();

    private:

        Bank::AccountType       _fromAccount,
                                _toAccount;
        Money                   _amount;
  };

//</pre><a name="InquiryTransaction"><hr><h3>Interface for class InquiryTransaction</h3><pre>
class InquiryTransaction : public Transaction
  {
    public:

        InquiryTransaction(Session & session, ATM & atm, Bank & bank);

        Status::Code getTransactionSpecificsFromCustomer();
        Status::Code sendToBank();
        Status::Code finishApprovedTransaction();

    private:

        Bank::AccountType       _fromAccount;
  };

//</pre></body></html>

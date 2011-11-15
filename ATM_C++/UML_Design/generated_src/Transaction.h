#ifndef Transaction_h
#define Transaction_h

class ATM;
class Session;

class Transaction {

 public:

    ATM *myATM;

    Session *mySession;
};

#endif // Transaction_h

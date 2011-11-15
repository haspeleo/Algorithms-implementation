#ifndef Session_h
#define Session_h

#include <vector>

#include "Transaction.h"

class ATM;

class Session {

 public:

    /**
     * @element-type ATM
     */
    ATM *myATM;

    /**
     * @element-type Transaction
     */
    std::vector< Transaction > myTransaction;

    /**
     * @element-type ATM
     */
    ATM *myATM;
};

#endif // Session_h

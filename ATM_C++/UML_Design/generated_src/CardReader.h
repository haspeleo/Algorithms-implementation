#ifndef CardReader_h
#define CardReader_h

#include "Card.h"

class ATM;

class CardReader : public Card {

 public:

    ATM *myATM;
};

#endif // CardReader_h

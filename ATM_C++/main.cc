// <html><head><title>ATM Simulation - main program</title></head><body><h2>ATM Simulation - main program</h2><pre>

/*
 * Example ATM simulation - file main.cc
 *
 * This file contains the main program for the ATM simulation
 *
 * Copyright (c) 1996, 1997 - Russell C. Bjork
 *
 */

#include <iostream.h>
#include "sysdep.h"
#include "status.h"
#include "money.h"
#include "bank.h"
#include "session.h"
#include "transaction.h"
#include "atmparts.h"
#include "atm.h"

#define ATM_NUMBER 42
#define ATM_LOCATION "GORDON COLLEGE"

main()
  { 
    Bank theBank;
    ATM theATM(ATM_NUMBER, ATM_LOCATION, theBank);
    Money initialCash = theATM.startupOperation();
    theATM.serviceCustomers(initialCash); 
  }

//</pre></body></html>

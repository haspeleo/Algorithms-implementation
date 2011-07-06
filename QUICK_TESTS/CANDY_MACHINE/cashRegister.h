#ifndef CASHREGISTER_H_
#define CASHREGISTER_H_

class cashRegister
{
public:
	int currentBalance();
	    //Function to show the current amount in the cash register.
	    //Postcondition: The value of cashOnHand is returned.
	void acceptAmount(int amountIn);
	    //Function to receive the amount deposited by the customer and
	    //update the amount in the cash register.
	    //Postcondition:cashOnHand=cashOnHand+amountIn.
	cashRegister(int cashIn=500);
	    //Constructor to set the cash in the register to a specific amount.
	    //Postcondition:cashOnHand=cashIn.
	    //If no value is specified when the object is declared,the default
	    //value assigned to cashOnHand is 500.

private:
	int cashOnHand;            //variable to store the cash in the register.
};


#endif






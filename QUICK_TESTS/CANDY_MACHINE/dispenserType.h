#ifndef DISPENSERTYPE_H_
#define DISPENSERTYPE_H_

class dispenserType
{
public:
	int count();
	    //Function to show the number of items in the machine.
	    //Postcondition:The value of the data member numberOfItems is returned.
	int productCost();
	    //Function to show the cost of the item.The value of the data member cost 
	    //is returned .
	    //Postcondition:The value of cost is returned.
	void makeSale();
	    //Function to reduce the number of items by 1.
	    //Postcondition:numberOfItems.
	dispenserType(int setNoOfItems=50,int setCost=50);
	    //Constructor to set the cost and number of items in the dispenser specified by
	    // the user.
	    //Postcondition:numberOfItems=setNoOfItems;cost=setCost
	    //If no value is specified for a parameter, then its default value is assigned to the
	    //corresponding data member.

private:
	int numberOfItems;                  //variable to store the number of items in the dispenser
	int cost;                           //variable to store the cost of an item.
};


#endif








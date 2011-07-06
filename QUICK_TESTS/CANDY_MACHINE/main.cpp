#include <iostream>
#include "cashRegister.h"


#include "dispenserType.h"

using namespace std;
void showSelection();


void sellProduct(dispenserType& product,cashRegister& pCounter);


int main()
{
	cashRegister counter;
	dispenserType candy(100,50);
	dispenserType chips(100,65);
	dispenserType gum(75,45);
	dispenserType cookies(100,85);



	int choice;


	showSelection();
	cin>>choice;


	while(choice!=9)
	{
		switch(choice)
		{
		case 1:sellProduct(candy,counter);break;
		case 2:sellProduct(chips,counter);break;
		case 3:sellProduct(gum,counter);break;
		case 4:sellProduct(cookies,counter);break;
		default:cout<<"Bad Selection"<<endl;
		}//end switch


		showSelection();
		cin>>choice;


	}//end while

    return 0;    
}//end main






void showSelection()
{
	cout<<"*** Welcome to Shelly's Candy Shop***"<<endl;
	cout<<"To select an item,enter"<<endl;
	cout<<"1 for Candy"<<endl;
	cout<<"2 for Chips"<<endl;
	cout<<"3 for Gum"<<endl;
	cout<<"4 for Cookies"<<endl;
	cout<<"9 to exit"<<endl;

}//end showSelection



void sellProduct(dispenserType& product,cashRegister& pCounter)
{
	int amount;         //variable to hold the amount entered
	int amount2;        //variable to hold the extra amount needed


if(product.count()>0)
{
	cout<<"Please deposit"<<product.productCost()<<"cents"<<endl;
	cin>>amount;

	if(amount<product.productCost())
	{
		cout<<"Please deposit another"<<product.productCost()-amount<<"cents"<<endl;
		cin>>amount2;
		amount=amount+amount2;

	}


	if(amount>=product.productCost())
	{
		pCounter.acceptAmount(amount);
		product.makeSale();
		cout<<"Collect your item at the bottom"<<"and enjoy"<<endl;


	}
	else
	{
		cout<<"The amount is not enough."<<"Collect what you deposited"<<endl;
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<endl;
	}
}
else
        cout<<"Sorry this item is sold out."<<endl;
}//end sellProduct.





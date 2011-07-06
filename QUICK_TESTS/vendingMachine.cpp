#include <iostream>
#include <cstdlib>
using namespace std;


int dol,cen;
unsigned int cb=0,ch;
void convert(int cb)
{
     dol=0;cen=0;
     while (cb>=100) {
		     cb-=100;
		     dol++;
		    }
     cen=cb;
}
 
void read()
{
		convert(cb);
		cout <<"The current balance is\t" <<dol << " dollars and "<< cen <<" cents "<<endl;
		cout <<"Please choose from one of these options"<<endl;
		cout <<"\n";
 
		cout <<"5 -	Deposit a nickle\t";
		cout <<"45 -	Buy some gum for 45 cents"<<endl;
 
		cout <<"10 -	Deposit a dime\t"<<"\t";
		cout <<"55 -	Buy crackers for 55 cents"<<endl;
 
		cout <<"25 -	Deposit a quarter\t";
		cout <<"60 -	Buy a soft drink for 60 cents"<<endl;
 
		cout <<"50 -	Deposit a half dollar\t";
		cout <<"70 -	Buy a candy bar for 70 cents"<<endl;
 
		cout <<"100 -	Deposit a dollar bill\t";
		cout <<"85 -	Buy some chips for 85 cents"<<endl;
 
		cout <<"0 -	Request coin return and quit\t";
 
		cout <<"\n";
 
		cout << "\n" <<"Enter a number to choose an option:\t";
		cin >> ch;
}
int main()
{
       system("cls");    //clrscr();
       cout <<"This program simulates a vending machine"<<endl;
       read();
       while (ch!=0)
		{
		 cout<<"\n\n";
		 if (ch==5) { cb+=5;ch=-1;}
		 if (ch==10){ cb+=10;ch=-1;}
		 if (ch==25) {cb+=25;ch=-1;}
		 if (ch==50) {cb+=50;ch=-1;}
		 if (ch==100) {cb+=100;ch=-1;}
 
		 if (ch==0)
			{
			 cout<<"Quiting\n";
			 while (cb%100==0&&cb>0) {cout<<"Returning a dollar\n";cb-=100;}
			 while (cb%50==0&&cb>0) {cout<<"Returning a half dollar\n";cb-=50;}
			 while (cb%25==0&&cb>0) {cout<<"Returning a quarter\n";cb-=25;}
			 while (cb%10==0&&cb>0) {cout<<"Returning a dinme\n";cb-=10;}
			 while (cb%5==0&&cb>0) {cout<<"Returning a nickel\n";cb-=5;}
			 ch=-1;
			}
 
		 if (ch==45)
			{
			if (cb>45) {
				    cout<<"Here is your gum\n";
				    cb-=45;
				   }
				else cout<<"Error:Deposit more money\n";
			ch=-1;}
		 if (ch==55)
		 {
			if (cb>55) {
				    cout<<"Here are your crackers\n";
				    cb-=55;
				   }
				else cout<<"Error:Deposit more money\n";
			ch=-1;}
		 if (ch==60)
			{
			if (cb>60) {
				    cout<<"Here is your soft drink\n";
				    cb-=60;
				   }
				else cout<<"Error:Deposit more money\n";
			ch=-1;}
		 if (ch==70)
			{
			if (cb>70) {
				    cout<<"Here is your candy bar\n";
				    cb-=70;
				   }
				else cout<<"Error:Deposit more money\n";
			ch=-1;}
		 if (ch==85)
			{
			if (cb>85) {
				    cout<<"Here are your chips\n";
				    cb-=85;
				   }
				else cout<<"Error:Deposit more money\n";
			ch=-1;}
		read();
       }
       cout << "GoodBye\n";
return 0;
}

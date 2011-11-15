/**
* Author: http://javacodee.blogspot.com/
* Date: Aug 1, 2007
* Time: 11:30:18 PM
*/
import java.util.Scanner;

public class AtmMachine
{
private double availableBal =80;
private double totalBal =100;
Scanner input = new Scanner(System.in);

public int userAccount()
{
System.out.print("Enter your account number: ");
int account;
account = input.nextInt();

return account;
}

public int userPin()
{
System.out.print("Enter your pin number: ");
int pin;
pin =input.nextInt();

return pin;
}

public void startAtm()
{
userAccount();
userPin();
drawMainMenu();
}

public void drawMainMenu()
{
int selection;

System.out.println("\nATM main menu:");
System.out.println("1 - View account balance");
System.out.println("2 - Withdraw funds");
System.out.println("3 - Add funds");
System.out.println("4 - Terminate transaction");
System.out.print("Choice: ");
selection =input.nextInt();

switch(selection)
{
case 1:
viewAccountInfo();
break;
case 2:
withdraw();
break;
case 3:
addFunds();
break;
case 4:
System.out.println("Thank you for using this ATM!!! goodbye");
}
}

public void viewAccountInfo()
{
System.out.println("Account Information:");
System.out.println("\t--Total balance: $"+totalBal);
System.out.println("\t--Available balance: $"+availableBal);
drawMainMenu();
}

public void deposit(int depAmount)
{
System.out.println("\n***Please insert your money now...***");
totalBal =totalBal +depAmount;
availableBal =availableBal +depAmount;
}

public void checkNsf(int withdrawAmount)
{
if(totalBal -withdrawAmount < 0)
System.out.println("\n***ERROR!!! Insufficient funds in you accout***");
else
{
totalBal =totalBal -withdrawAmount;
availableBal =availableBal -withdrawAmount;
System.out.println("\n***Please take your money now...***");
}
}

public void addFunds()
{
int addSelection;

System.out.println("Deposit funds:");
System.out.println("1 - $20");
System.out.println("2 - $40");
System.out.println("3 - $60");
System.out.println("4 - $100");
System.out.println("5 - Back to main menu");
System.out.print("Choice: ");
addSelection =input.nextInt();

switch(addSelection)
{
case 1:
deposit(20);
drawMainMenu();
break;
case 2:
deposit(40);
drawMainMenu();
break;
case 3:
deposit(60);
drawMainMenu();
break;
case 4:
deposit(100);
drawMainMenu();
break;
case 5:
drawMainMenu();
break;
}
}

public void withdraw()
{
int withdrawSelection;

System.out.println("Withdraw money:");
System.out.println("1 - $20");
System.out.println("2 - $40");
System.out.println("3 - $60");
System.out.println("4 - $100");
System.out.println("5 - Back to main menu");
System.out.print("Choice: ");
withdrawSelection =input.nextInt();

switch(withdrawSelection)
{
case 1:
checkNsf(20);
drawMainMenu();
break;
case 2:
checkNsf(40);
drawMainMenu();
break;
case 3:
checkNsf(60);
drawMainMenu();
break;
case 4:
checkNsf(100);
drawMainMenu();
break;
case 5:
drawMainMenu();
break;
}
}

public static void main(String args[])
{
AtmMachine myAtm = new AtmMachine();
myAtm.startAtm();
}
}
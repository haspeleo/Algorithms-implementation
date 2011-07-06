
import java.util.*;
import java.io.*;

public class ATMs extends Thread {
    static final int numATMs = 4;
    static Bank bnk;
    PrintStream out;
    BufferedReader in;
    int atmnum;


    ATMs(int num, PrintStream out, BufferedReader in) {
        this.atmnum = num;
        this.out = out;
        this.in = in;
    }
     public static void main (String [] args) {

        bnk = Bank.getBank();
        ATMs atm [] = new ATMs[numATMs];
        for (int i = 0; i < numATMs; i ++) {
            atm[i] = new ATMs(i, outdevice(i), indevice(i));
            atm[i].start();
        }

    }

public void run() {
        while (true) {
            try {
                out.print("Account ID > ");
                String id = in.readLine();
                Account acc = bnk.get(id);
                if (acc == null) throw new Exception();
                out.println("Password > ");
                String pass = in.readLine();
                if (!acc.is_password(pass)) throw new Exception;
                out.println("Your Balance is: "+acc.getBal());
                out.println("Deposit or Withdraw amount > ");
                int val = in.read();
                if (acc.getBal() + val > 0)
                    acc.post(val);
                else
                    throw new Exception();
                out.println("Your balance is "+acc.getBal());
            }catch (Exception e) {
                out.println("Invalid input, restart");
            }
        }
    }



}

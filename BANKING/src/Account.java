
import java.util.*;

public class Account {

    String id;
    String password;
    int balance;

    Account(String id, String password, int balance) {
        this.id = id;
        this.password = password;
        this.balance = balance;
    }

    boolean is_password(String password) {
        return password == this.password;
    }

    int getBal() {
        return balance;
    }

    void post(int v) {
        balance = balance + v;
    }

}//Account

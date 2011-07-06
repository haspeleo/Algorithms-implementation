package com.inria;
import java.util.Random;

public class Producer implements Runnable {
    private Drop drop;
    public Producer(Drop drop) {
        this.drop = drop;
    }

    public void run() {
      String importantInfo[] = {
            "Mares eat oats",
            "Does eat oats",
            "Little lambs eat ivy",
            "A kid will eat ivy too"
        };

        Random random = new Random();
        for (int i=0 ; i < importantInfo.length; i++) {
            try {
               drop.put(importantInfo[i]);
              Thread.sleep(random.nextInt(5000));
              System.out.println("Producer: next production in "+random.nextInt(5000));
            } catch (InterruptedException e) {}
     }
      drop.put("DONE");
    }

}

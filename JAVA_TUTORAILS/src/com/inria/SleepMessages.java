package com.inria;

/**
 *
 * @author doghmen
 */

public class SleepMessages {

    public static void main (String [] args) throws InterruptedException {

    String importantInfo [] = {"Monday", "Tuesday", "Wednesday", "Thursday",
                               "Friday", "Saturday", "Sunday"};

    for (int i=0; i < 7; i++) {
        try {
            System.out.println("Day N°"+(i+1)+": "+importantInfo[i]);
            Thread.sleep(1000);
            } catch (InterruptedException ie) {
            System.out.println("We have been interrupted. No more messages "+ie);
            return;
            }
        //Print message
        System.out.println(importantInfo[i]);
        }

    }


}
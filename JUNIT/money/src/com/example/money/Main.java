package com.example.money;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		
		Money m1 = new Money(10, "USD");
		Money m2 = new Money(20, "USD");
		
		Money m3 = m1.add(m2);
		
		System.out.println(">> Amount: "+m3.amount());
		System.out.println(">> Currency: "+m3.currency());
		
	}

}

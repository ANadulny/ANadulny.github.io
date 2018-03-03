package com.adrian;

public class Main {

    public static void main(String[] args) {
        String myString = "This is a string";
        System.out.println("myString is equal to " + myString);
        myString = myString + ", and this is more.";
        System.out.println("myString is equal to " + myString);
        myString += " \u00A9 2015";
        System.out.println("myString is equal to " + myString);

        String numbreString = "250.55";
        numbreString += "49.95";
        System.out.println("The result is " + numbreString);

        String lastString = "10";
        int myInt = 50;
        lastString += myInt;
        System.out.println("Last String is equal to " + lastString);
        double doubleNumber = 120.47;
        lastString += doubleNumber;
        System.out.println("LastString value: " + lastString);
    }
}

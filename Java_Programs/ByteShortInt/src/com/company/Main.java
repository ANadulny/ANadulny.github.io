package com.company;

public class Main {

    public static void main(String[] args) {

        // int has a width of 32
        int myValue = 1000;
        int myMaxValue = 2_147_483_647;

        // byte has a width of 8
        byte myByteValue = 127;
        byte myNewByteValue = (byte) (myByteValue / 2);
        System.out.println("myNewByteValue = " + myNewByteValue);

        // short has a width of 16

        // long has a value of 64
        long myLongValue = 100L;

    }
}


import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class BigIntegerClass{
    public static void main(String[] args) {
        //convert String to BigINteger
        BigInteger b1 = new BigInteger("22");
        System.out.println("b1 "+b1);

        //base 2
        BigInteger b2 = new BigInteger("1011", 2);
        System.out.println("b2 "+b2);

        //Take Input
        Scanner sc = new Scanner(System.in);
        BigInteger b3 = sc.nextBigInteger();
        System.out.println(b3);

        //Addition
        BigInteger b4 = b3.add(b1);
        System.out.println(b4);

        //Bits different from sign bit
        System.out.println(b2.bitCount());

        //Int to BigInt
        int number = 1;
        BigInteger one= BigInteger.valueOf(number);
        System.out.println(one);

        //Big Integer with value one
        System.out.println(BigInteger.ONE);

        //Power of two BigIntegers
        BigInteger a = BigInteger.valueOf(5);
        System.out.println(a.pow(6));//exponent is int 

        //GCD
        System.out.println(b1.gcd(b2));

        //Modulus
        System.out.println(b1.mod(b2));

        //Multiplication
        System.out.println(b1.multiply(b2));

        //Subtraction
        System.out.println(b1.subtract(b2));

        //Division
        System.out.println(b1.divide(b2));

        //Compare
        System.out.println(b1.compareTo(b2));

        //Max
        System.out.println(b1.max(b2));

        //Min
        System.out.println(b1.min(b2));

        //Negate
        System.out.println(b1.negate());//example -22

        //Not
        System.out.println(b1.not());//example -23

        //Shift Left
        System.out.println(b1.shiftLeft(2));//example 88

        //Shift Right
        System.out.println(b1.shiftRight(2));//example 5

        //To String
        System.out.println(b1.toString());

        //To String with base
        System.out.println(b1.toString(2)); //example 10110

        //To byte array
        byte[] byteArray = b1.toByteArray(); //example [0, 22]

        //To int
        System.out.println(b1.intValue());

        //To long
        System.out.println(b1.longValue());

        //ppcm
        System.out.println(b1.multiply(b2).divide(b1.gcd(b2))); 




    }
}
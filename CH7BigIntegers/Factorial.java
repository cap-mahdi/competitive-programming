
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

public class Factorial {
    static BigInteger factorial(int N){
        BigInteger result = BigInteger.ONE;
        for(int i = 2 ; i<=N; i++){
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(factorial(N));
    }
}   

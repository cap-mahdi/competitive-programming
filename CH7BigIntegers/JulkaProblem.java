import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
public class JulkaProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger N = sc.nextBigInteger();
        BigInteger K = sc.nextBigInteger();

        BigInteger x = (N.subtract(K)).divide(BigInteger.valueOf(2));
        BigInteger y = x.add(K);

        System.out.println(y);
        System.out.println(x);
    }
}

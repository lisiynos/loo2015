import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class forest_as_bigint {
    public void run() throws IOException {
        in = new Scanner(new File("forest.in"));
        out = new PrintWriter("forest.out");

        BigInteger a = BigInteger.valueOf(in.nextInt());
        BigInteger k = BigInteger.valueOf(in.nextLong());
        BigInteger b = BigInteger.valueOf(in.nextInt());
        BigInteger m = BigInteger.valueOf(in.nextLong());
        BigInteger x = BigInteger.valueOf(in.nextLong());

        BigInteger L = BigInteger.ZERO;
        BigInteger R = BigInteger.valueOf(2).multiply(x);
        while (R.subtract(L).compareTo(BigInteger.ONE) > 0) {
            BigInteger v = R.add(L).divide(BigInteger.valueOf(2));
            BigInteger dmi = v.divide(k).multiply(k.subtract(BigInteger.ONE)).multiply(a).add(v.mod(k).multiply(a));
            BigInteger fed = v.divide(m).multiply(m.subtract(BigInteger.ONE)).multiply(b).add(v.mod(m).multiply(b));
            if (dmi.add(fed).compareTo(x) < 0) {
                L = v;
            } else {
                R = v;
            }
        }

        out.println(R);

        out.close();
    }

    Scanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new forest_as_bigint().run();
    }

}
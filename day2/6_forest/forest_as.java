import java.util.*;
import java.io.*;

public class forest_as {
    public void run() throws IOException {
        in = new Scanner(new File("forest.in"));
        out = new PrintWriter("forest.out");

        long a = in.nextInt();
        long k = in.nextLong();
        long b = in.nextInt();
        long m = in.nextLong();
        long x = in.nextLong();

        long L = 0;
        long R = (2 * x + a + b - 1) / (a + b);
        while (L < R - 1) {
            long v = (L + R) / 2;
            long dmi = (v / k) * (k - 1) * a + (v % k) * a;
            long fed = (v / m) * (m - 1) * b + (v % m) * b;
            if (dmi + fed < x) {
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
        new forest_as().run();
    }

}
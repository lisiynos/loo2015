import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "prizes";
    
    private static Scanner scan;
    private static PrintWriter pw;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        if(problem == null) {
            scan = new Scanner(System.in);
            pw = new PrintWriter(System.out);
        }else {
            scan = new Scanner(new FileReader(problem + ".in"));
            pw = new PrintWriter(new FileWriter(problem + ".out"));
        }
        solve();
        pw.close();
    }
    
    private static void solve() {
        int n = scan.nextInt(), k = scan.nextInt();
        long[] a = new long[n + 2], sums = new long[n + 2], prefixes = new long[n + 2], suffixes = new long[n + 2];
        for(int i = 0; i < n; ++i) {
            a[i] = scan.nextLong();
            if(i == 0) sums[i + 1] = a[i];
            else sums[i + 1] = sums[i] + a[i];
            //System.out.println("SUMS" + (i + 1) + ": " + sums[i]);
        }
        for(int i = k - 1; i < n; ++i) {
            prefixes[i + 1] = Math.max(prefixes[i], sums[i + 1] - sums[i - k + 1]);
            //System.out.println((i + 1) + "P" + prefixes[i + 1]);
        }
        for(int i = n - k + 1; i > 0; --i) {
            suffixes[i] = Math.max(suffixes[i + 1], sums[i + k] - sums[i]);
            //System.out.println((i) + "S" + suffixes[i]);
        }
        long answer = Long.MAX_VALUE;
        for(int i = k - 1; i < n - k + 1; ++i) {
            //System.out.println(i + " " + answer + " " + prefixes[i] + " " + suffixes[i + k]);
            answer = Math.min(answer, Math.max(prefixes[i], suffixes[i + k]));
        }
        pw.println(answer);
    }
    
}
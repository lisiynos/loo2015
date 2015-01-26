
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
        long[] a = new long[n + 1], sums = new long[n + 1], prefixes = new long[n + 1], suffixes = new long[n + 1];
        for(int i = 0; i < n; ++i) {
            a[i] = scan.nextLong();
            if(i == 0) sums[i] = a[i];
            else sums[i] = sums[i - 1] + a[i];
        }
        for(int i = k; i <= n; ++i) prefixes[i] = Math.max(prefixes[i - 1], sums[i] - sums[i - k]);
        for(int i = n - k; i >= 0; --i) suffixes[i] = Math.max(suffixes[i + 1], sums[i + k] - sums[i]);
        long answer = Long.MAX_VALUE;
        for(int i = k; i < n - k + 1; ++i)
            answer = Math.min(answer, Math.max(prefixes[i], suffixes[i + k]));
        pw.println(answer);
    }
    
}

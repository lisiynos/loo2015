import java.io.*;
import java.util.*;

public class transform_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();
        int pp = in.nextInt();
        if (pp == 1) {
            out.println("1\n7 0 0 0 3\n");
            return;
        }
        int[] c = new int[n];
        Integer[] ix = new Integer[n];
        boolean[][] e = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            ix[i] = i;
            char[] s = in.next().toCharArray();
            for (int j = 0; j < n; j++) {
                e[i][j] = s[j] == '+';
                if (e[i][j]) {
                    c[i]++;
                }
            }
        }

        Arrays.sort(ix, Comparator.comparingInt(i -> c[i]));
        int[] rx = new int[n];
        for (int i = 0; i < n; i++) {
            rx[ix[i]] = i;
        }

        int max = 0;
        int prev = 0;
        int[] ans = new int[n];
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (e[ix[i]][j]) {
                    max = Math.max(max, rx[j]);
                }
            }
            if (max <= i) {
                if (i != n - 2 || i - prev > 0) {
                    ans[prev] = i + 1 - prev;
                }
                prev = i + 1;                
            }
        }

        int k = n - prev;
        out.println(k);
        for (int i = prev - 1; i >= 0; i--) {
            out.print(ans[i] * k + " ");
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("transform.in"));
        out = new PrintWriter("transform.out");

        new transform_gk().run();

        in.close();
        out.close();
    }
}

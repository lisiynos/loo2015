import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * User: Aksenov Vitaly
 * Date: 17.10.14
 * Time: 19:35
 */
public class prizes_va_30 {
    public static void main(String[] args) {
        new prizes_va_30().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        int best = Integer.MAX_VALUE;
        for (int i = 0; i < n - k + 1; i++) {
            int max = Integer.MIN_VALUE;
            for (int j = 0; j < n - k + 1; j++) {
                if (Math.max(i, j) < Math.min(i + k, j + k))
                    continue;
                int s2 = 0;
                for (int q = 0; q < k; q++) {
                    s2 += a[j + q];
                }
                max = Math.max(max, s2);
            }

            best = Math.min(best, max);
        }
        out.println(best);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("prizes.in"));
            out = new PrintWriter("prizes.out");

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

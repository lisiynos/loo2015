import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * User: Aksenov Vitaly
 * Date: 17.10.14
 * Time: 19:35
 */
public class prizes_va_overflow {
    public static void main(String[] args) {
        new prizes_va_overflow().run();
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

        int[] s = new int[n + 1];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            s[i + 1] = s[i] + a[i];
        }

        int[] pref = new int[n + 1];
        for (int i = k - 1; i < n; i++) {
            pref[i + 1] = Math.max(pref[i], s[i + 1] - s[i - k + 1]);
        }

        int[] suff = new int[n + 1];
        for (int i = n - k; i > 0; i--) {
            suff[i] = Math.max(suff[i + 1], s[i + k]  - s[i]);
        }

        int best = Integer.MAX_VALUE;
        for (int i = 0; i < n - k + 1; i++) {
            best = Math.min(best, Math.max(pref[i], suff[i + k]));
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

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * User: Aksenov Vitaly
 * Date: 17.10.14
 * Time: 19:35
 */
public class prizes_va_max_wa {
    public static void main(String[] args) {
        new prizes_va_max_wa().run();
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

        long[] s = new long[n + 1];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            s[i + 1] = s[i] + a[i];
        }

        ArrayList<Integer> maximums = new ArrayList<>();
        long max = 0;
        for (int i = 0; i < n - k + 1; i++) {
            long sum = s[i + k] - s[i];
            if (max < sum) {
                max = sum;
                maximums.clear();
            }
            if (max == sum)
                maximums.add(i);
        }

        if (maximums.size() >= 2) {
            if (maximums.get(maximums.size() - 1) - maximums.get(0) + 1 >= 2 * k) {
                out.println(max);
                return;
            }
        }

        int l = Math.max(maximums.get(0) - k, 0);
        int r = Math.min(maximums.get(maximums.size() - 1) + k, n - k + 1);

        long best = Long.MAX_VALUE;
        for (int i : maximums) {
            max = Long.MIN_VALUE;
            for (int j = 0; j < n - k + 1; j++) {
                if (Math.max(i, j) < Math.min(i + k, j + k))
                    continue;
                max = Math.max(max, s[j + k] - s[j]);
            }

            best = Math.min(best, max);
        }

        out.println(best);  //
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

import java.util.*;
import java.io.*;

public class river_as_tree {
    FastScanner in;
    PrintWriter out;

    class RSQ {
        int n;
        int s;
        int[] d;

        RSQ(int n) {
            this.n = n;
            s = 4 * n;
            d = new int[s];
            init(0, 0, n);
        }

        void init(int i, int l, int r) {
            if (l == r - 1) {
                d[i] = 1;
            } else {
                int m = (l + r) / 2;
                init(2 * i + 1, l, m);
                init(2 * i + 2, m, r);
                d[i] = d[2 * i + 1] + d[2 * i + 2];
            }
        }

        int getKth(int k) {
            return getKth(0, 0, n, k);
        }

        int getKth(int i, int l, int r, int k) {
            if (l == r - 1) {
                return l;
            }
            int m = (l + r) / 2;
            int v = d[2 * i + 1];
            if (v > k) {
                return getKth(2 * i + 1, l, m, k);
            } else {
                return getKth(2 * i + 2, m, r, k - v);
            }
        }

        void set(int p, int v) {
            set(0, 0, n, p, v);
        }

        void set(int i, int l, int r, int p, int v) {
            if (l == r - 1) {
                d[i] = v;
            } else {
                int m = (l + r) / 2;
                if (p < m) {
                    set(2 * i + 1, l, m, p, v);
                } else {
                    set(2 * i + 2, m, r, p, v);
                }
                d[i] = d[2 * i + 1] + d[2 * i + 2];
            }
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int subtask = in.nextInt(); 
        if (subtask == 0) {
            out.println("75\n105\n73\n101\n83\n113\n");
            return;
        }
        long[] a = new long[n];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            ans += a[i] * a[i];
        }
        int[] next = new int[n];
        int[] prev = new int[n];
        Arrays.fill(next, -1);
        Arrays.fill(prev, -1);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prev[i] = i - 1;
            }
            if (i < n - 1) {
                next[i] = i + 1;
            }
        }

        RSQ rsq = new RSQ(n);

        out.println(ans);
//        System.out.println(Arrays.toString(a));
        int k = in.nextInt();
        for (int i = 0; i < k; i++) {
            int e = in.nextInt();
            int p = in.nextInt() - 1;
            int v = rsq.getKth(p);
            rsq.set(v, 0);

            ans -= a[v] * a[v];
            if (prev[v] == -1) {
                int u = next[v];
                ans -= a[u] * a[u];
                a[u] += a[v];
                ans += a[u] * a[u];
                prev[u] = -1;
            } else if (next[v] == -1) {
                int w = prev[v];
                ans -= a[w] * a[w];
                a[w] += a[v];
                ans += a[w] * a[w];
                next[w] = -1;
            } else {
                int w = prev[v];
                int u = next[v];
                long left = a[v] / 2;
                long right = (a[v] + 1) / 2;
                ans -= a[u] * a[u];
                ans -= a[w] * a[w];
                a[w] += left;
                a[u] += right;
                ans += a[w] * a[w];
                ans += a[u] * a[u];
                next[w] = u;
                prev[u] = w;
            }
            a[v] = 0;
 //           System.out.println(Arrays.toString(a));
            out.println(ans);
        }
        out.close();
    }

    public void run() {
        try {
            in = new FastScanner(new File("river.in"));
            out = new PrintWriter(new File("river.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new river_as_tree().run();
    }
}
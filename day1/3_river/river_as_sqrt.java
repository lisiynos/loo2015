import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class river_as_sqrt {
    FastScanner in;
    PrintWriter out;

    final int BLOCK_SIZE = 1024;

    class Block {
        int n;
        int[] a;

        Block(int n, int[] a) {
            this.n = n;
            this.a = new int[BLOCK_SIZE];
            System.arraycopy(a, 0, this.a, 0, n);
        }

        int getKth(int k) {
            return a[k];
        }

        void remove(int p) {
            for (int j = p; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
        }

        void insert(int p, int v) {
            for (int i = n; i > p; i--) {
                a[i] = a[i - 1];
            }
            a[p] = v;
            n++;
        }

        Block[] split() {
            Block b1 = new Block(n / 2, Arrays.copyOfRange(a, 0, n / 2));
            Block b2 = new Block(n - n / 2, Arrays.copyOfRange(a, n / 2, n));
            return new Block[]{b1, b2};
        }
    }

    class SQRTD {
        int n;
        ArrayList<Block> blocks;

        SQRTD(int n) {
            this.n = n;
            int bn = (n + BLOCK_SIZE - 1) / (BLOCK_SIZE / 2);
            int k = 0;
            blocks = new ArrayList<>();
            for (int i = 0; i < bn; i++) {
                int len = BLOCK_SIZE / 2;
                if (n - k < len) {
                    len = n - k;
                }
                int[] a = new int[len];
                for (int j = 0; j < len; j++) {
                    a[j] = k++;
                }
                blocks.add(new Block(len, a));
            }
        }

        int getKth(int k) {
            int b = 0;
            while (blocks.get(b).n <= k) {
                k -= blocks.get(b).n;
                b++;
            }
            return blocks.get(b).getKth(k);
        }

        void remove(int k) {
            int b = 0;
            while (blocks.get(b).n <= k) {
                k -= blocks.get(b).n;
                b++;
            }
            blocks.get(b).remove(k);
        }

        void insert(int k, int v) {
            int b = 0;
            while (b < blocks.size() && blocks.get(b).n <= k) {
                k -= blocks.get(b).n;
                b++;
            }
            if (b == blocks.size()) {
                blocks.add(new Block(0, new int[BLOCK_SIZE]));
            }
            blocks.get(b).insert(k, v);
            if (blocks.get(b).n == BLOCK_SIZE) {
                Block[] nb = blocks.get(b).split();
                blocks.set(b, nb[0]);
                blocks.add(b + 1, nb[1]);
            }
        }

    }

    final static int MAXK = 100_000;

    void print(int p, int next[], long[] a) {
        int sp = p;
        while (p != -1) {
            System.out.print(p + " ");
            p = next[p];
        }
        System.out.println();
        p = sp;
        while (p != -1) {
            System.out.print(a[p] + " ");
            p = next[p];
        }
        System.out.println();
        System.out.println();
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        in.nextInt(); // ignore subtask
        long[] a = new long[n + 2 * MAXK];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            ans += a[i] * a[i];
        }
        int[] next = new int[n + 2 * MAXK];
        int[] prev = new int[n + 2 * MAXK];
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

        SQRTD dec = new SQRTD(n);

        out.println(ans);
        int t = n;
//        System.out.println(Arrays.toString(a));
//        print(dec.getKth(0), next, a);
        int k = in.nextInt();
        for (int i = 0; i < k; i++) {
            int e = in.nextInt();
            int p = in.nextInt() - 1;
            int v = dec.getKth(p);
//            System.out.println(v);
            ans -= a[v] * a[v];
            dec.remove(p);

            if (e == 1) {
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
            } else {
                dec.insert(p, t);
                dec.insert(p + 1, t + 1);

                int w = prev[v];
                int u = next[v];
                long left = a[v] / 2;
                long right = (a[v] + 1) / 2;
                a[t] = left;
                a[t + 1] = right;
                ans += a[t] * a[t];
                ans += a[t + 1] * a[t + 1];
                if (w != -1) {
                    next[w] = t;
                }
                next[t] = t + 1;
                next[t + 1] = u;
                prev[t] = w;
                prev[t + 1] = t;
                if (u != -1) {
                    prev[u] = t + 1;
                }

                t += 2;
            }
//            print(dec.getKth(0), next, a);
//            System.out.println(Arrays.toString(a));
            out.println(ans);
        }
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
        new river_as_sqrt().run();
    }
}
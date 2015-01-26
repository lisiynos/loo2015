import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class river_as_cartesian {
    FastScanner in;
    PrintWriter out;

    final static Random rnd = new Random(2348972497L);

    class Node {
        Node l;
        Node r;
        int sz;
        int v;
        int y;

        Node(int v) {
            this.l = null;
            this.r = null;
            this.v = v;
            y = rnd.nextInt();
            update();
        }

        void update() {
            sz = 1;
            if (l != null) {
                sz += l.sz;
            }
            if (r != null) {
                sz += r.sz;
            }
        }
    }

    Node merge(Node a, Node b) {
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        if (a.y < b.y) {
            a.r = merge(a.r, b);
            a.update();
            return a;
        } else {
            b.l = merge(a, b.l);
            b.update();
            return b;
        }
    }

    int size(Node n) {
        if (n == null) {
            return 0;
        }
        return n.sz;
    }

    Node[] split(Node a, int k) {
        if (a == null) {
            Node[] ret = new Node[2];
            return ret;
        }

        if (size(a.l) >= k) {
            Node[] v = split(a.l, k);
            a.l = v[1];
            a.update();
            v[1] = a;
            return v;
        } else {
            Node[] v = split(a.r, k - 1 - size(a.l));
            a.r = v[0];
            a.update();
            v[0] = a;
            return v;
        }
    }

    class Rope {
        int n;
        Node root;

        Rope(int n) {
            this.n = n;
            root = null;
            for (int i = 0; i < n; i++) {
                root = merge(root, new Node(i));
            }
        }

        int getKth(int k) {
            Node v = root;
            while (size(v.l) != k) {
                if (size(v.l) > k) {
                    v = v.l;
                } else {
                    k -= size(v.l) + 1;
                    v = v.r;
                }
            }
            return v.v;
        }

        void remove(int k) {
            Node[] v = split(root, k);
            Node[] w = split(v[1], 1);
            root = merge(v[0], w[1]);
        }

        void insert(int k, int v) {
            Node[] x = split(root, k);
            root = merge(x[0], new Node(v));
            root = merge(root, x[1]);
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

        Rope dec = new Rope(n);

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
        new river_as_cartesian().run();
    }
}
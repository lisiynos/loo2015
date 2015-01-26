import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;

public class Validate {
    final int MAXN = 100_000;
    final int MAXX = 10_000;
    final int MAXM = 100_000;

    public void run() {
        StrictScanner inf = new StrictScanner(System.in);
        int n = inf.nextInt();
        ensureLimits(n, 2, MAXN, "incorrect n");
        int subtask = inf.nextInt();
        ensureLimits(subtask, 0, 4, "subtask");
        inf.nextLine();

        long[] a = new long[n + 2 * MAXM];


        for (int i = 0; i < n; i++) {
            a[i] = inf.nextInt();
            ensureLimits(a[i], 1, MAXX, "incorrect element in 2nd line");
        }
        inf.nextLine();
        int[] next = new int[n + 2 * MAXM];
        int[] prev = new int[n + 2 * MAXM];
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

        int t = n;

        int m = inf.nextInt();
        ensureLimits(m, 1, MAXM, "incorrect k");
        inf.nextLine();
        for (int i = 0; i < m; i++) {
            int e = inf.nextInt();
            int p = inf.nextInt() - 1;
            ensureLimits(e, 1, 2, "bad type " + line(4 + i));
            ensureLimits(p, 0, size(dec.root) - 1, "bad v " + line(4 + i));
            int v = dec.getKth(p);
            ensure(a[v] > 1, "length of segment = 1 in " + line(4 + i));

            dec.remove(p);

            if (e == 1) {
                if (prev[v] == -1) {
                    int u = next[v];
                    a[u] += a[v];
                    prev[u] = -1;
                } else if (next[v] == -1) {
                    int w = prev[v];
                    a[w] += a[v];
                    next[w] = -1;
                } else {
                    int w = prev[v];
                    int u = next[v];
                    long left = a[v] / 2;
                    long right = (a[v] + 1) / 2;
                    a[w] += left;
                    a[u] += right;
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


            inf.nextLine();
        }
        inf.close();
    }

    public static void main(String[] args) {
        new Validate().run();
    }

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



    public class StrictScanner {
        private final BufferedReader in;
        private String line = "";
        private int pos;
        private int lineNo;

        public StrictScanner(InputStream source) {
            in = new BufferedReader(new InputStreamReader(source));
            nextLine();
        }

        public void close() {
            ensure(line == null, "Extra data at the end of file");
            try {
                in.close();
            } catch (IOException e) {
                throw new AssertionError("Failed to close with " + e);
            }
        }

        public void nextLine() {
            ensure(line != null, "EOF");
            ensure(pos == line.length(), "Extra characters on line " + lineNo);
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new AssertionError("Failed to read line with " + e);
            }
            pos = 0;
            lineNo++;
        }

        public String getNextLine() {
            String st = "";
            while (!isEoln()) {
                st = st + next();
            }
            return st;
        }


        public boolean isEoln() {
            return (pos == line.length());
        }

        public String next() {
            ensure(line != null, "EOF");
            ensure(line.length() > 0, "Empty line " + lineNo);
            if (pos == 0)
                ensure(line.charAt(0) > ' ', "Line " + lineNo
                        + " starts with whitespace");
            else {
                ensure(pos < line.length(), "Line " + lineNo + " is over");
                ensure(line.charAt(pos) == ' ', "Wrong whitespace on line "
                        + lineNo);
                pos++;
                ensure(pos < line.length(), "Line " + lineNo + " is over");
                ensure(line.charAt(0) > ' ', "Line " + lineNo
                        + " has double whitespace");
            }
            StringBuilder sb = new StringBuilder();
            while (pos < line.length() && line.charAt(pos) > ' ')
                sb.append(line.charAt(pos++));
            return sb.toString();
        }

        public int nextInt() {
            String s = next();
            ensure(s.length() == 1 || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Integer.parseInt(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }

        public long nextLong() {
            String s = next();
            ensure(s.length() == 1 || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Long.parseLong(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }

        public double nextDouble() {
            String s = next();
            ensure(s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Double.parseDouble(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }
    }

    static void ensure(boolean b, String message) {
        if (!b) {
            throw new AssertionError(message);
        }
    }

    void ensureString(String s, String alph, String text) {
        for (int i = 0; i < s.length(); i++) {
            ensure(alph.indexOf(s.charAt(i)) != -1, text);
        }
    }

    void ensureLimits(long n, long from, long to, String name) {
        ensure(from <= n && n <= to, name + " must be from " + from + " to "
                + to);
    }

    void ensureLimits(int n, int from, int to, String name) {
        ensure(from <= n && n <= to, name + " must be from " + from + " to "
                + to);
    }

    String line(int x) {
        return "Problem in line #" + Integer.toString(x);
    }

}


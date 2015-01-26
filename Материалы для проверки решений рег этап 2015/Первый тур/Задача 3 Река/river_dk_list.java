import java.io.*;
import java.util.StringTokenizer;

public class river_dk_list {
    final int MAXT = 700000;
    Element[] list;
    long ans = 0;
    int t = 1;

    class Element {
        long x;
        Element l, r;

        Element(long x) {
            this.x = x;
        }

        Element(long x, Element l) {
            this.x = x;
            this.l = l;
        }

        Element(long x, Element l, Element r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }
    }

    void add(int x, int t) {
        Element element = new Element(x, list[t - 1]);
        list[t - 1].r = element;
        list[t] = element;
        ans += x * x;
    }

    void split(Element delete) {
        ans -= delete.x * delete.x;
        Element new1 = new Element(delete.x / 2, delete.l);
        Element new2 = new Element(delete.x / 2 + (delete.x % 2), new1, delete.r);
        new1.r = new2;
        delete.l.r = new1;
        delete.r.l = new2;
        list[t] = new1;
        list[t + 1] = new2;
        t += 2;
        ans += new1.x * new1.x + new2.x * new2.x;

    }

    void goBroke(Element delete) {

        ans -= delete.x * delete.x;
        long l, r;
        if (delete.l.x == -1) {
            l = 0;
            r = delete.x;
        } else {
            if (delete.r.x == -1) {
                l = delete.x;
                r = 0;
            } else {
                l = delete.x / 2;
                r = (delete.x / 2 + delete.x % 2);
            }
        }
        ans -= (delete.l.x * delete.l.x) + (delete.r.x * delete.r.x);
        delete.l.x += l;
        delete.r.x += r;
        ans += (delete.l.x * delete.l.x) + (delete.r.x * delete.r.x);

        delete.l.r = delete.r;
        delete.r.l = delete.l;

    }

    public void solve() throws IOException {
        int n = nextInt();
        nextInt(); // ignore subtask
        Element left = new Element(-1);
        list = new Element[MAXT + 1];
        list[0] = left;

        for (int i = 0; i < n; i++) {
            int x = nextInt();
            add(x, t);
            t++;
        }
        Element right = new Element(-1);
        right.l = list[t - 1];
        list[t - 1].r = right;
        Element cur = left;
        int i = 0;
        int m = nextInt();
        out.println(ans);
        for (int q = 0; q < m; q++) {
            int type = nextInt();
            int v = nextInt();
            while (v > i) {
                i++;
                cur = cur.r;
            }
            while (v < i) {
                i--;
                cur = cur.l;
            }

            if (type == 1) {
                goBroke(cur);
                cur = cur.r;

            } else {
                split(cur);
                cur = list[t - 2];
            }
            out.println(ans);
        }
    }


    void run() throws IOException {      /*
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);*/
        br = new BufferedReader(new FileReader("river.in"));
        out = new PrintWriter("river.out");
        solve();
        out.close();
        br.close();
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    char nextChar() throws IOException {
        return (char) (br.read());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }

    public static void main(String[] args) throws IOException {
        new river_dk_list().run();
    }


}

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author: pashka
 */
public class transform_pm {

    private boolean[] z;
    private int[] p;
    private int pc;
    private int n;
    private boolean[][] a;
    private int[] c;

    private void solve() {
        n = in.nextInt();
        int mode = in.nextInt();
        a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j) == '+';
            }
        }
        z = new boolean[n];
        p = new int[n];
        pc = 0;
        for (int i = 0; i < n; i++) {
            dfs1(i);
        }
        Arrays.fill(z, false);
        c = new int[n];
        int cc = 0;
        for (int i = n - 1; i >= 0; i--)
            if (!z[p[i]]) {
                dfs2(p[i], cc++);
            }
        int[] sz = new int[n];
        for (int i = 0; i < n; i++) {
            sz[c[i]]++;
        }

        int[] res = new int[n + 1];
        int k = sz[0];
        res[k] += (n - k) * (n - k - 1) / 2;

        int s = k;
        for (int i = 1; i < cc; i++) {
            s += sz[i];
            res[s] += sz[i] * k;
        }

        int[] p = new int[n];
        int pn = 0;

        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                for (int j = 0; j <= pn; j++) {
                    if (j == pn || a[i][p[j]]) {
                        System.arraycopy(p, j, p, j + 1, pn - j);
                        p[j] = i;
                        pn++;
                        break;
                    }
                }
            }
        }

        if (k > 1) {

            int[] c = new int[n];
            int cn = 0;
            for (int i = 0; i < pn; i++) {
                if (a[p[i]][p[0]]) {
                    System.arraycopy(p, 0, c, 0, i + 1);
                    cn = i + 1;
                    break;
                }
            }

            for (int i = cn; i < pn; i++) {
                for (int j = 0; j < cn; j++) {
                    int jj = (j + 1) % cn;
                    if (a[c[j]][p[cn]] && a[p[i]][c[jj]]) {
                        System.arraycopy(c, j + 1, c, j + 2 + i - cn, cn - j - 1);
                        System.arraycopy(p, cn, c, j + 1, i - cn + 1);
                        cn = i + 1;
                        break;
                    }
                }
            }

            if (cn != k) {
                throw new RuntimeException();
            }
            if (cn > 1) {
                for (int i = 0; i < cn; i++) {
                    if (!a[c[i]][c[(i + 1) % cn]]) {
                        throw new RuntimeException();
                    }
                }
            }

            res[k] += k * (k - 1) / 2 - k;

            int[] r = new int[2 * k];
            for (int i = 0; i < k; i++) {
                r[i] = i;
                for (int j = i + 1; j < k; j++) {
                    if (i == 0 && j == k - 1) continue;
                    if (a[c[j % k]][c[i]]) {
                        r[i] = j;
                    }
                }
            }
            for (int i = 0; i < k; i++) {
                int rr = i;
                for (int j = i; ; j++) {
                    if (j > rr) {
                        res[j - i]++;
                        break;
                    }
                    rr = Math.max(rr, r[j]);
                }
                for (int j = i + 2; j < k + i; j++) {
                    if (a[c[i]][c[j % k]]) {
                        r[j] = i + k;
                    }
                }
            }
        }

        //hack
        res[1] += res[2];
        res[2] = 0;

        out.println(k);
        for (int i = mode == 0 ? k + 1 : 1; i <= n; i++) {
            out.print(res[i] + " ");
        }
        out.println();
    }

    private void dfs2(int i, int cc) {
        if (z[i]) return;
        z[i] = true;
        c[i] = cc;
        for (int j = 0; j < n; j++)
            if (a[j][i])
                dfs2(j, cc);
    }

    private void dfs1(int i) {
        if (z[i]) return;
        z[i] = true;
        for (int j = 0; j < n; j++)
            if (a[i][j])
                dfs1(j);
        p[pc++] = i;
    }


    private Scanner in;
    private PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        new transform_pm().run();
    }

    private void run() throws FileNotFoundException {
        in = new Scanner(new File("transform.in"));
        out = new PrintWriter("transform.out");
        solve();
        out.close();
    }

}

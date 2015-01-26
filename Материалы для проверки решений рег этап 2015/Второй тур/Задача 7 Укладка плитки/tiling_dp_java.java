import java.io.*;
import java.util.*;

public class tiling_dp_java {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new tiling_dp_java().run();
    }

    final int maxn = 100000;
    final int mod = 1000_000_007;

    int[][][] dp;
    int[][] used;
    int[] msk;

    void add(int row, int mskLeft, int mskRight, int x) {
        dp[row][mskLeft][mskRight] += x;
        if (dp[row][mskLeft][mskRight] >= mod) {
            dp[row][mskLeft][mskRight] -= mod;
        }
    }

    int getBit(int msk, int bit) {
        return ((msk >> bit) & 1);
    }

    public void solve() throws IOException {
        int n = nextInt(), k = nextInt();
        used = new int[n + 1][2];
        for (int i = 0; i < k; i++) {
            int x = nextInt(), y = nextInt();
            used[x][y - 1] = 1;
        }

        msk = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            msk[i] |= used[i][0];
            msk[i] |= 2 * used[i][1];
        } 

        dp = new int[n + 1][4][4];
        dp[1][0][0] = 2;
        dp[1][0][1] = dp[1][0][2] = 1;
        dp[1][0][3] = 1;

        for (int i = 2; i <= n; i++)
        for (int mskLeft = 0; mskLeft < 4; mskLeft++)
        for (int mskRight = 0; mskRight < 4; mskRight++) {
            dp[i][mskLeft][mskRight] = 0;
            if (mskRight == 3) {
                dp[i][mskLeft][mskRight] = dp[i - 1][msk[i - 2]][mskLeft];
                continue;
            }
            if (mskLeft == 3) {
                add(i, mskLeft, mskRight, (2 - getBit(mskRight, 0) - getBit(mskRight, 1)) * dp[i - 1][msk[i - 2]][mskLeft] % mod);
                continue;
            }
            if (mskRight == 0) {
                add(i, mskLeft, mskRight, dp[i - 1][msk[i - 2]][mskLeft] * 2 % mod);
                if (mskLeft == 0) {
                    add(i, mskLeft, mskRight, i >= 3 ? dp[i - 2][msk[i - 3]][msk[i - 2]] : 1);
                    add(i, mskLeft, mskRight, (dp[i - 1][msk[i - 2]][2] + dp[i - 1][msk[i - 2]][1]) % mod);
                } else {
                    add(i, mskLeft, mskRight, i >= 3 ? dp[i - 2][msk[i - 3]][msk[i - 2]] : 1);
                }
                continue;
            }
            for (int bit = 0; bit < 2; bit++) {
                if (getBit(mskRight, bit) == 0)
                    add(i, mskLeft, mskRight, dp[i - 1][msk[i - 2]][mskLeft]);
                if (getBit(mskRight, bit) == 0 && getBit(mskLeft, bit) == 0)
                    add(i, mskLeft, mskRight, dp[i - 1][msk[i - 2]][mskLeft | (1 << bit)]);
            }
        }
        out.println(dp[n][msk[n - 1]][msk[n]]);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("tiling.in"));
            out = new PrintWriter("tiling.out"); 
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
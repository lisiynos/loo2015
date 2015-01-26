import java.util.*;
import java.io.*;

public class alligator_as {
    public void run() throws IOException {
        in = new FastScanner(new FileInputStream("alligator.in"));
        out = new PrintWriter(new FileOutputStream("alligator.out"));

        int n = in.nextInt();
        int m = in.nextInt();
        int[][] field = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < m; j++) {
                field[i][j] = "NESW.".indexOf(s.charAt(j));
            }
        }

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        int[][][] next = new int[4][n][m];
        boolean[][] canGo = new boolean[n][m];

        int[] q = new int[n * m];
        int hd = 0;
        int tl = 0;

		for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        	    if (i == 0 || field[i - 1][j] < 4) {
        	        next[0][i][j] = i - 1;
        	    } else {
        	        next[0][i][j] = next[0][i - 1][j];
        	    }
        	    if (j == 0 || field[i][j - 1] < 4) {
        	        next[3][i][j] = j - 1;
        	    } else {
        	        next[3][i][j] = next[3][i][j - 1];
        	    }
        	}
    	}
    
	    for (int i = n - 1; i >= 0; i--) {
	        for (int j = m - 1; j >= 0; j--) {
	            if (i == n - 1 || field[i + 1][j] < 4) {
	                next[2][i][j] = i + 1;
	            } else {
	                next[2][i][j] = next[2][i + 1][j];
    	        }
    	        if (j == m - 1 || field[i][j + 1] < 4) {
        	        next[1][i][j] = j + 1;
        	    } else {
        	        next[1][i][j] = next[1][i][j + 1];
        	    }
        	}
    	}

    	for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
	       	    	int bound = k % 2 == 0 ? n : m;
    	            if (field[i][j] == k && (next[k][i][j] == -1 || next[k][i][j] == bound)) {
                        canGo[i][j] = true;
                        q[tl++] = i * m + j;
                	}
	            }
    	    }
	    }

        int ans = 0;
        while (hd < tl) {
            ans++;
            int i = q[hd] / m;
            int j = q[hd] % m;
            hd++;

            for (int k = 0; k < 4; k++) {
                int ni = i;
                int nj = j;
                if (dx[k] != 0) {
                    ni = next[k][i][j];
                } else {
                    nj = next[k][i][j];
                }
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    int nk = k ^ 2;
                    next[nk][ni][nj] = next[nk][i][j];
	                int bound = nk % 2 == 0 ? n : m;
                    if (nk == field[ni][nj] && !canGo[ni][nj] && (next[nk][ni][nj] == -1 || next[nk][ni][nj] == bound)) {
                        canGo[ni][nj] = true;
                        q[tl++] = ni * m + nj;
                    }
                }
            }
        }

        out.println(ans);

        out.close();
    }

    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new alligator_as().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            }
            return st.nextToken();
       }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * Meow :*
 */
public class java {
    
    private static final String problem = "tiling";
    private static FastReader scan;
    private static PrintWriter pw;
    
    public static void main(String[] args) throws IOException {
        if(problem == null) {
            scan = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
            pw = new PrintWriter(System.out);
        }else {
            scan = new FastReader(new BufferedReader(new FileReader(problem + ".in")));
            pw = new PrintWriter(new FileWriter(problem + ".out"));
        }
        solve();
        pw.close();
    }
    
    private static final int module = (int) 1e9 + 7, f = 1, s = 1 << 1;
    
    private static void solve() {
        int n = scan.nextInt(), k = scan.nextInt();
        int[] mask = new int[n + 1];
        for(int i = 0; i < k; ++i) mask[scan.nextInt()] |= 1 << scan.nextInt() - 1;
        long st[][] = new long[n + 1][4];
        st[0][0] = st[0][3] = 1;
        st[0][1] = st[0][2] = 0;
        for(int i = 1; i <= n; ++i) {
            if(mask[i] == 0) {
                st[i][2] = st[i - 1][0] + st[i - 1][1];
                st[i][2] %= module;
                st[i][1] = st[i - 1][0] + st[i - 1][2];
                st[i][1] %= module;
                st[i][3] = st[i][1] + st[i][2] + st[i - 1][3];
                st[i][3] %= module;
                for(int j = 0; j < 4; ++j) st[i][0] += st[i - 1][j];
                st[i][0] %= module;
            }else if((mask[i] & (f + s)) == f + s) {
                st[i][1] = st[i][2] = 0;
                st[i][0] = st[i][3] = st[i - 1][0];
            }else if((mask[i] & s) == 0) {
                st[i][1] = 0;
                st[i][2] = st[i - 1][0];
                st[i][0] = st[i][3] = st[i][2] + st[i - 1][2];
                st[i][0] %= module;
                st[i][3] %= module;
            }else {
                st[i][1] = st[i - 1][0];
                st[i][2] = 0;
                st[i][0] = st[i][3] = st[i - 1][0] + st[i - 1][1];
                st[i][0] %= module;
                st[i][3] %= module;
            }
        }
        //for(int i = 0; i <= n; ++i) pw.println(i + " " + st[i][0] + " " + st[i][1] + " " + st[i][2] + " " + st[i][3]);
        pw.println(st[n][0]);
    }
    
    private static class FastReader {
        
        private final BufferedReader reader;
        private StringTokenizer tokens;
        
        public FastReader(BufferedReader reader) throws IOException {
            this.reader = reader;
            tokens = new StringTokenizer(reader.readLine());
        }
        
        public String next() {
            try {
                if(tokens.hasMoreTokens()) return tokens.nextToken();
                tokens = new StringTokenizer(reader.readLine());
                return tokens.nextToken();
            }catch(IOException ex) {
                ex.printStackTrace();
            }
            return null;
        }
        
        public int nextInt() {
            return Integer.valueOf(next());
        }
        
        public long nextLong() {
            return Long.valueOf(next());
        }
        
    }
    
}
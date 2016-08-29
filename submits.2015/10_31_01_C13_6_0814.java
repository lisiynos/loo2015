
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
    
    private static final String problem = "forest";
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
    
    private static void solve() {
        long a = scan.nextLong(), k = scan.nextLong(), b = scan.nextLong(), m = scan.nextLong(), x = scan.nextLong();
        long l = 0, r = (x / (a + b) << 1) + 1;
        while(l + 1 < r) {
            long mid = (l + r) >> 1;
            long first = a * ((k - 1) * (mid / k) + mid % k),
                    second = b * ((m - 1) * (mid / m) + mid % m);
            if(first + second < x) l = mid;
            else r = mid;
        }
        pw.println(r);
    }
    
    private static class FastReader {
        
        private BufferedReader reader;
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

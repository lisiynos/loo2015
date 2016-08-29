
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
    
    private static final String problem = "circle";
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
        int n = scan.nextInt();
        pw.println((n & 1) == 0 ? n * (n - 2) : n * (n - 1));
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

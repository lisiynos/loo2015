import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "search";
    
    private static Scanner scan;
    private static FastReader fr;
    private static PrintWriter pw;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        if(problem == null) {
            //scan = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            fr = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
        }else {
            //scan = new Scanner(new FileReader(problem + ".in"));
            fr = new FastReader(new BufferedReader(new FileReader(problem + ".in")));
            pw = new PrintWriter(new FileWriter(problem + ".out"));
        }
        solve();
        pw.close();
    }
    
    //Answer is 42 :O
    private static void solve() throws IOException {
        int n = fr.nextInt(), p = fr.nextInt(), k;
        HashMap<String, Integer> templates = new HashMap();
        List<String> servers = new ArrayList(), dirs = new ArrayList();
        System.out.println(n + " " + p);
        for(int i = 0; i < n; ++i) {
            String s = fr.next();
            int amount = templates.containsKey(s) ? templates.get(s) : 0;
            templates.put(s, ++amount);
        }
        k = fr.nextInt();
        for(int i = 0; i < k; ++i) {
            String ad = fr.next(), server = ad, dir = "";
            int j = ad.indexOf('/');
            if(j != -1) {
                server = ad.substring(0, j);
                dir = ad.substring(j, ad.length());
            }
            servers.add(server);
            server = "*." + server;
            for(j = 1; j != -1; j = server.indexOf('.', j + 1))
                servers.add('*' + server.substring(j, server.length()));
            dirs.add(dir);
            dir += "/*";
            for(j = dir.lastIndexOf('/'); j != -1; j = dir.lastIndexOf('/', j - 1))
                dirs.add(dir.substring(0, j + 1) + '*');
            int answer = 0;
            for(String s : servers)
                for(String d : dirs) {
                    String sum = s + d;
                    Integer ss = templates.get(sum);
                    if(ss != null) answer += ss;
                }
            pw.println(answer);
            servers.clear();
            dirs.clear();
        }
    }
    
    private static class FastReader {
        
        private StringTokenizer tokens;
        private BufferedReader reader;
        
        public FastReader(BufferedReader reader) throws IOException {
            tokens = new StringTokenizer(reader.readLine());
            this.reader = reader;
        }
        
        public String next() throws IOException {
            if(tokens.hasMoreTokens()) return tokens.nextToken();
            else {
                tokens = new StringTokenizer(reader.readLine());
                return tokens.nextToken();
            }
        }
        
        public int nextInt() throws IOException {
            return Integer.valueOf(next());
        }
        
    }
    
}
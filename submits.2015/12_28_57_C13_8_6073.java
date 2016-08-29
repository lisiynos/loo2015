
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 *
 * Wtf?
 */
public class java {
    
    private static final String problem = "transform";
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
    
    private static int[] portals;
    private static boolean[][] graph;
    private static City[] cities_max, reversed_max, cities_min, reversed_min;
    private static int max, pmaxid, min, pminid;
    private static long[] answers;
    
    private static void solve() {
        int n = scan.nextInt(), p = scan.nextInt();
        if(p == 1) {
            pw.println(1);
            pw.println("7 0 0 0 3");
            return;
        }
        max = pmaxid = 0;
        min = pminid = Integer.MAX_VALUE;
        graph = new boolean[n][n];
        portals = new int[n];
        cities_max = new City[n];
        cities_min = new City[n];
        reversed_max = new City[n];
        reversed_min = new City[n];
        answers = new long[n];
        for(int i = 0; i < n; ++i) {
            char[] chars = scan.next().toCharArray();
            for(int j = 0; j < n; ++j)
                if(chars[j] == '+') {
                    ++portals[i];
                    graph[i][j] = true;
                }
            cities_max[i] = cities_min[i] = new City(i);
        }
        Arrays.sort(cities_max);
        Arrays.sort(cities_min, new CustomComparator());
        for(int i = 0; i < n; ++i)
            reversed_max[cities_max[i].id] = reversed_min[cities_min[i].id] = new City(i);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(graph[cities_max[i].id][j]) max = Math.max(max, reversed_max[j].id);
                if(graph[cities_min[i].id][j]) min += Math.min(min, reversed_min[j].id);
            }
            //System.out.println((i + 1) + " " + pmaxid + " " + pminid + " " + max + " " + min);
            if(max <= i) {
                if(i > pmaxid)
                    answers[pmaxid] = i + 1 - pmaxid;
                pmaxid = i + 1;
            }
        }
        int k = pmaxid + 1 - n;
        pw.println(k);
        for(int i = pmaxid - 2; i >= 0; --i) pw.print(answers[i] * k + " ");
    }
    
    private static class CustomComparator implements Comparator<City> {

        @Override
        public int compare(City t, City t1) {
            return portals[t1.id] - portals[t.id];
        }
        
    }
    
    private static class City implements Comparable<City> {
        
        public int id;
        
        public City(int id) {
            this.id = id;
        }
        
        @Override
        public int compareTo(City c) {
            return portals[id] - portals[c.id];
        }
        
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

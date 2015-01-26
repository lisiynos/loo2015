import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "search";
    
    private static Scanner scan;
    private static PrintWriter pw;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        if(problem == null) {
            scan = new Scanner(System.in);
            pw = new PrintWriter(System.out);
        }else {
            scan = new Scanner(new FileReader(problem + ".in"));
            pw = new PrintWriter(new FileWriter(problem + ".out"));
        }
        solve();
        pw.close();
    }
    
    //Answer is 42 :O
    private static void solve() {
        int n = scan.nextInt(), p = scan.nextInt(), k;
        HashMap<String, Integer> templates = new HashMap();
        List<String> servers = new ArrayList(), dirs = new ArrayList();
        for(int i = 0; i < n; ++i) {
            String s = scan.next();
            int amount = templates.containsKey(s) ? templates.get(s) : 0;
            templates.put(s, ++amount);
        }
        k = scan.nextInt();
        for(int i = 0; i < k; ++i) {
            String ad = scan.next(), server = ad, dir = "";
            if(ad.contains("/")) {
                int j = ad.indexOf('/');
                server = ad.substring(0, j);
                dir = ad.substring(j, ad.length());
            }
            servers.add(server);
            server = "*." + server;
            for(int j = 1; j != -1; j = server.indexOf('.', j + 1))
                servers.add('*' + server.substring(j, server.length()));
            dirs.add(dir);
            dir += "/*";
            for(int j = dir.lastIndexOf('/'); j != -1; j = dir.lastIndexOf('/', j - 1))
                dirs.add(dir.substring(0, j + 1) + '*');
            int answer = 0;
            for(String s : servers)
                for(String d : dirs) {
                    String sum = s + d;
                    if(templates.containsKey(sum)) answer += templates.get(sum);
                }
            pw.println(answer);
            servers.clear();
            dirs.clear();
        }
    }
    
}
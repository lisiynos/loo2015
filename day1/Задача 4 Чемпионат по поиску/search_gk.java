import java.io.*;
import java.util.*;

public class search_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        Map<String, Integer> filters = new HashMap<String, Integer>();
        int n = in.nextInt();
        in.nextInt();
        for (int i = 0; i < n; i++) {
            String filter = in.next();
            if (filters.get(filter) == null) {
                filters.put(filter, 0);
            }
            filters.put(filter, filters.get(filter) + 1);
        }

        int m = in.nextInt();
        List<String> hosts = new ArrayList<String>();
        List<String> paths = new ArrayList<String>();
        for (int i = 0; i < m; i++) {
            String url = in.next();
            String host;
            String path;
            int index = url.indexOf("/") ;
            if (index >= 0) {
                host = url.substring(0, index);
                path = url.substring(index);
            } else {
                host = url;
                path = "";
            }

            hosts.clear();
            hosts.add(host);
            host = "*." + host;
            index = host.indexOf('.');
            while (index >= 0) {                
                hosts.add("*" + host.substring(index));
                index = host.indexOf('.', index + 1);
            }

            paths.clear();
            paths.add(path);
            path = path + "/*";
            index = path.lastIndexOf('/');
            while (index >= 0) {
                paths.add(path.substring(0, index + 1) + "*");
                index = path.lastIndexOf('/', index - 1);
            }            

            int a = 0;
            for (String h : hosts) {
                for (String  p : paths) {
                    Integer d = filters.get(h + p);
                    if (d != null) {
                        a += d;
                    }
                }
            }
            out.println(a);
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("search.in"));
        out = new PrintWriter("search.out");

        new search_gk().run();

        in.close();
        out.close();
    }
}

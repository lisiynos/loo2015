
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "hall";
    
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
    
    private static void solve() {
        long a = scan.nextLong(), b = scan.nextLong(), c = scan.nextLong(), d = scan.nextLong(),
                answer = 0;
        for(long x = 1; x < d >> 1 && x * x <= b; ++x) {
            long l1 = a / x; if(a % x != 0) ++l1;
            long l2 = (c + 1 - (x << 1)) >> 1;
            long l3 = b / x;
            long l4 = (d - (x << 1)) >> 1;
            long ymin = Math.max(l1, l2),
                    ymax = Math.min(l3, l4);
            //ystem.out.println(x + " " + ymin + " " + ymax);
            if(ymin < x) ymin = x;
            //System.out.println(x + " " + ymin + " " + ymax);
            if(ymax >= ymin) answer += ymax - ymin + 1;
        }
        pw.println(answer);
    }
    
}

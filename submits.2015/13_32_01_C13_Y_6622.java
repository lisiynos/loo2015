
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "alligator";
    
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
        int n = scan.nextInt(), m = scan.nextInt();
        scan.nextLine();
        Point[][] matrix = new Point[n][m];
        for(int i = 0; i < n; ++i) {
            char[] chars = scan.nextLine().toCharArray();
            for(int j = 0; j < m; ++j) {
                char c = chars[j];
                Point p = new Point(i, j);
                switch(c) {
                    case 'N': p.direction = 1; break;
                    case 'E': p.direction = 2; break;
                    case 'S': p.direction = 3; break;
                    case 'W': p.direction = 4; break;
                    default: p.direction = 0; break;
                }
                if(i == 0) p.up = none;
                else if(i == n - 1 && i - 1 > - 1) {
                    p.down = none;
                    p.up = matrix[i - 1][j].direction == 0 ? matrix[i - 1][j].up : new Pair(i - 1, j);
                }
                else if(i - 1 > -1) p.up = matrix[i - 1][j].direction == 0 ? matrix[i - 1][j].up : new Pair(i - 1, j);
                if(j == 0) p.left = none;
                else if(j == m - 1 && j - 1 > -1) {
                    p.right = none;
                    p.left = matrix[i][j - 1].direction == 0 ? matrix[i][j - 1].left : new Pair(i, j - 1);
                }else if(j - 1 > -1) p.left = matrix[i][j - 1].direction == 0 ? matrix[i][j - 1].left : new Pair(i, j - 1);
                matrix[i][j] = p;
            }
        }
        for(int i = n - 1; i >= 0; --i)
            for(int j = m - 1; j >= 0; --j) {
                Point p = matrix[i][j];
                if(i == 0 && i + 1 < n) p.down = matrix[i + 1][j].direction == 0 ? matrix[i + 1][j].down : new Pair(i + 1, j);
                else if(i == n - 1) p.down = none;
                else if(i + 1 < n) p.down = matrix[i + 1][j].direction == 0 ? matrix[i + 1][j].down : new Pair(i + 1, j);
                if(j == 0 && j + 1 < m) p.right = matrix[i][j + 1].direction == 0 ? matrix[i][j + 1].right : new Pair(i, j + 1);
                else if(j == m - 1) p.right = none;
                else if(j + 1 < m) p.right = matrix[i][j + 1].direction == 0 ? matrix[i][j + 1].right : new Pair(i, j + 1);
                matrix[i][j] = p;
            }
        List<Point> remove = new ArrayList();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                Point p = matrix[i][j];
                int dir = p.direction;
                //System.out.println(i + " " + j + " " + remove.size());
                if((dir == 1 && p.up == none) ||
                   (dir == 2 && p.right == none) ||
                   (dir == 3 && p.down == none) ||
                   (dir == 4 && p.left == none)) remove.add(p);
            }
        long answer = 0;
        while(!remove.isEmpty()) {
            Point p = remove.remove(0), p2;
            //System.out.println(p.x + " " + p.y);
            ++answer;
            p.direction = 0;
            Pair<Integer, Integer> pa = p.up;
            if(pa != none) {
                p2 = matrix[pa.a][pa.b];
                if((p2.down = p.down) == none && p2.direction == 3) remove.add(p2);
            }
            pa = p.right;
            //System.out.println(pa.a + " " + pa.b);
            if(pa != none) {
                p2 = matrix[pa.a][pa.b];
                if((p2.left = p.left) == none && p2.direction == 4) remove.add(p2);
            }
            pa = p.down;
            //System.out.println(pa.a + " " + pa.b);
            if(pa != none) {
                p2 = matrix[pa.a][pa.b];
                if((p2.up = p.up) == none && p2.direction == 1) remove.add(p2);
            }
            pa = p.left;
            //System.out.println(pa.a + " " + pa.b);
            if(pa != none) {
                p2 = matrix[pa.a][pa.b];
                if((p2.right = p.right) == none && p2.direction == 2) remove.add(p2);
            }
        }
        pw.println(answer);
    }
    
    private static class Point {
        
        public int x, y;
        public Pair<Integer, Integer> left, right, up, down;
        public int direction;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
    }
    
    private static final Pair<Integer, Integer> none = new Pair(-1, -1);
    
    private static class Pair<A, B> {
        
        public A a;
        public B b;
        
        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }
        
    }
    
}

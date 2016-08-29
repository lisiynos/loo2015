
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
 * Nya!
 */

public class java {
    
    private static final String problem = "river";
    
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
    
    private static final int max = 300001, bs = 1 << 10;
    private static int n, p, k, e, v, fs, left[], right[], l, r, counter, totalb, length, m;
    private static long answer, a[];
    private static final List<Block> blocks = new ArrayList();
    
    private static void solve() {
        n = scan.nextInt(); p = scan.nextInt();
        a = new long[max];
        left = new int[max];
        right = new int[max];
        Arrays.fill(left, -1);
        Arrays.fill(right, -1);
        answer = 0;
        counter = n;
        totalb = (n + bs - 1) / (bs >> 1);
        for(int i = 0; i < totalb; ++i) {
            length = bs >> 1;
            if(length > n - m) length = n - m;
            int[] mass = new int[length];
            for(int j = 0; j < length; ++j) mass[j] = m++;
            blocks.add(new Block(length, mass));
        }
        for(int i = 0; i < n; ++i) {
            a[i] = scan.nextLong();
            if(i != 0) left[i] = i - 1;
            if(i != n - 1) right[i] = i + 1;
            inc(i);
        }
        pw.println(answer);
        k = scan.nextInt();
        for(int i = 0; i < k; ++i) {
            e = scan.nextInt();
            fs = scan.nextInt() - 1;
            v = remove(fs);
            dec(v);
            l = left[v]; r = right[v];
            if(e == 1) {
                if(l == -1) {
                    dec(r);
                    a[r] += a[v];
                    inc(r);
                    left[r] = l;
                }else if(r == -1) {
                    dec(l);
                    a[l] += a[v];
                    inc(l);
                    right[l] = r;
                }else {
                    dec(l); dec(r);
                    a[l] += a[v] >> 1;
                    a[r] += (a[v] + 1) >> 1;
                    inc(l); inc(r);
                    left[r] = l;
                    right[l] = r;
                }
            }else {
                add(fs++, counter++);
                add(fs++, counter++);
                a[counter - 2] = a[v] >> 1;
                a[counter - 1] = (a[v] + 1) >> 1;
                inc(counter - 2); inc(counter - 1);
                left[counter - 2] = l;
                left[counter - 1] = counter - 2;
                right[counter - 1] = r;
                right[counter - 2] = counter - 1;
                if(l != -1) right[l] = counter - 2;
                if(r != -1) left[r] = counter - 1;
            }
            pw.println(answer);
        }
    }
    
    private static int remove(int id) {
        for(Block b : blocks) {
            if(b.n > id) return b.remove(id);
            id -= b.n;
        }
        return -1;
    }
    
    private static void add(int id, int value) {
        int bid = 0;
        for(; bid < blocks.size() && blocks.get(bid).n <= id; ++bid) id -= blocks.get(bid).n;
        if(bid == blocks.size()) blocks.add(new Block(0, new int[bs]));
        blocks.get(bid).add(bid, id, value);
    }
    
    private static class Block {
        
        public int n, mass[];
        
        public Block(int n, int[] mass) {
            this.n = n;
            this.mass = new int[bs];
            System.arraycopy(mass, 0, this.mass, 0, n);
        }
        
        public void add(int bid, int id, int value) {
            for(int i = n; i > id; --i) mass[i] = mass[i - 1];
            mass[id] = value;
            ++n;
            if(n == bs) split(bid);
        }
        
        public int remove(int id) {
            int r = mass[id];
            for(int i = id; i < n - 1; ++i) mass[i] = mass[i + 1];
            --n;
            return r;
        }
        
        public void split(int id) {
            if(n != bs) return;
            blocks.set(id++, new Block(n >> 1, Arrays.copyOfRange(mass, 0, n >> 1)));
            blocks.add(id, new Block((n + 1) >> 1, Arrays.copyOfRange(mass, n >> 1, n)));
        }
        
    }
    
    private static void inc(int v) {
        answer += a[v] * a[v];
    }
    
    private static void dec(int v) {
        answer -= a[v] * a[v];
    }
    
}

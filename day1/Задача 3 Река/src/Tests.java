import java.io.*;
import java.util.*;

public class Tests {
    public static void main(String[] args) throws IOException {
        new Tests().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int tNumber, tNumberPre;
    int subtask;
    Random rnd;
    final int MAXN = 100000;
    final int MAXM = 100000;
    final int MAXX = 10000;
    class Pair {
        int e, v;

        Pair(int e, int v) {
            this.e = e;
            this.v = v;
        }
    }

    void printPre(int[] array, ArrayList<Pair> changes) throws IOException {
        System.err.println("Preliminary...");
        if (tNumberPre < 10) {
            out = new PrintWriter("../preliminary/0" + tNumber);
        } else {
            out = new PrintWriter("../preliminary/" + tNumber);
        }
        tNumberPre++;

        out.println(array.length + " 0");
        out.print(array[0]);
        for (int i = 1; i < array.length; i++) {
            out.print(" " + array[i]);
        }
        out.println();
        out.println(changes.size());
        for (Pair pair : changes) {
            out.println(pair.e + " " + pair.v);
        }

        out.close();
    }
    void print(int[] array, ArrayList<Pair> changes) throws IOException {
        System.err.println(tNumber);
        if (tNumber < 10) {
            out = new PrintWriter("../tests/subtask" + subtask + "/0" + tNumber);
        } else {
            out = new PrintWriter("../tests/subtask" + subtask + "/" + tNumber);
        }
        tNumber++;

        out.println(array.length + " " + subtask);
        out.print(array[0]);
        for (int i = 1; i < array.length; i++) {
            out.print(" " + array[i]);
        }
        out.println();
        out.println(changes.size());
        for (Pair pair : changes) {
            out.println(pair.e + " " + pair.v);
        }

        out.close();
    }


    void genSimple() throws IOException {
        int[] t1 = {3, 5, 5, 4};
        ArrayList<Pair> changes = new ArrayList<Pair>();
        changes.add(new Pair(1, 1));
        changes.add(new Pair(2, 1));
        changes.add(new Pair(1, 3));
        changes.add(new Pair(2, 2));
        changes.add(new Pair(1, 3));
        tests.add("../preliminary/01   Sample test n = 4, k = 5");
        printPre(t1, changes);
    }

    //Group 1

    void genTest1(int n, int x) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = x;
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        while (n != 1) {
            changes.add(new Pair(1, 1));
            n--;
            if (n != 1) {
                changes.add(new Pair(1, n));
                n--;
            }
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Delete all segments except one, delete from left and right alternately. All events have first type");
        print(t1, changes);
    }

    void genTest2(int n, int x) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = x;
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        for (int i = n; i > 1; i--) {
            changes.add(new Pair(1, i));
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Delete all segments except one, delete from right, one by one. All events have first type");
        print(t1, changes);

    }

    void genTest3(int n) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) {
                t1[i] = 2;
            } else {
                t1[i] = 1;
            }
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        boolean[] f = new boolean[n];
        int oldn = n;
        int i = 1;
        while (changes.size() != oldn - 1) {
            for (; i < n; i++) {
                changes.add(new Pair(1, i + 1));
                n--;
            }
            i = i % n;
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Delete all segments except one, one skip, one delete, one skip, one delete etc. All events have first type");
        print(t1, changes);

    }

    void genTest4(int n) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = 1;
        }
        int j = n / 2 + 1;
        t1[n / 2] = 2;
        ArrayList<Pair> changes = new ArrayList<Pair>();

        changes.add(new Pair(1, j));
        for (int i = 1; i < (n / 2); i++) {
            changes.add(new Pair(1, j - i));
            changes.add(new Pair(1, j - i));
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Delete all segments except one from middle. All events have first type");
        print(t1, changes);
    }

    void genTest5(int n, int x) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = rnd.nextInt(x / 2) + x / 2;
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        int count = n;
        for (int i = 0; i < n - 1; i++) {
            changes.add(new Pair(1, rnd.nextInt(count) + 1));
            count--;
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Random test. All events have first type");

        print(t1, changes);
    }


    //Group 2

    void genTest6(int n, int maxx, boolean isMax, int m) throws IOException {
        int[] arr = new int[n];
        int t = n;
        ArrayList<Pair> available = new ArrayList<Pair>();
        for (int i = 0; i < n; i++) {
            if (isMax) {
                arr[i] = maxx;
            }
            else {
                arr[i] = rnd.nextInt(maxx) + 1;
            }
            available.add(new Pair(i, arr[i]));
        }

        ArrayList<Pair> changes = new ArrayList<Pair>();

        for (int i = 0; i < m; i++) {
            int j = rnd.nextInt(t);
            changes.add(new Pair(2, j + 1));
            t++;
        }

        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Random test, where all events have second type");
        print(arr, changes);
    }

    void genTest7(int n, int x) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = x;
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        int i = 1;
        for (int k = 0; k < n / 2; k++) {
            changes.add(new Pair(2, i + 1));
            i += 3;
        }
        i = 0;
        for (int k = 0; k < n / 2; k++) {
            changes.add(new Pair(1, i + 1));
            i += 2;
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Split all segments on odd positions and delete segments on even positions.");
        print(t1, changes);
    }

    void genTest8(int n, int x) throws IOException {
        int[] t1 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = x;
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        int i = 1;
        for (int k = 0; k < n / 2; k++) {
            changes.add(new Pair(2, i + 1));
            i += 3;
        }
        i = 1;
        for (int k = 0; k < n / 2; k++) {
            changes.add(new Pair(1, i + 1));
            i += 2;
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Split all segments on odd positions and delete all even new segments (with v > n)");
        print(t1, changes);
    }

    void genTest9(int n, int m, int x) throws IOException {
        int[] t1 = new int[n];
        ArrayDeque<Pair> deque = new ArrayDeque<Pair>();
        for (int i = 0; i < n; i++) {
            t1[i] = x;
            deque.addLast(new Pair(x, i + 1));
        }
        ArrayList<Pair> changes = new ArrayList<Pair>();
        int t = n + 1;
        int l = 1;
        for (int i = 0; i < m; i++) {

            Pair tmp = deque.pollFirst();
            while (tmp.e == 1) {
                tmp = deque.pollFirst();
                l++;
            }
            //System.err.println(tmp.e + " " + tmp.v);
            changes.add(new Pair(2, l));
            deque.addFirst(new Pair(tmp.e % 2 + tmp.e / 2, t + 1));
            deque.addFirst(new Pair(tmp.e / 2, t));
            t += 2;
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Split first segment while can split. Then skip and split second while can etc. All events have second type");
        print(t1, changes);
    }

    void genTest10(int n, int maxx, boolean isMax, int m) throws IOException {
        int[] arr = new int[n];
        int t = n;
        ArrayList<Pair> available = new ArrayList<Pair>();
        for (int i = 0; i < n; i++) {
            if (isMax) {
                arr[i] = maxx;
            }
            else {
                arr[i] = rnd.nextInt(maxx / 2) + maxx / 2;
            }
            available.add(new Pair(i, arr[i]));
        }

        ArrayList<Pair> changes = new ArrayList<Pair>();
        int count = n;
        for (int i = 0; i < m; i++) {
            int j = rnd.nextInt(count) + 1;
            int type = rnd.nextInt(2) + 1;
            if (type == 2) {
                changes.add(new Pair(2, j + 1));
                count++;
            }
            else {
                changes.add(new Pair(1, j));
                count--;//Тут немного не хорошо, может валидатор не пустить. Простите за русский.
            }
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Random test");
        print(arr, changes);
    }

    void genRandTestWithStep(int n, int m, int maxx, int l, int r) throws IOException {
        int[] arr = new int[n];
        int t = n;
        ArrayList<Pair> available = new ArrayList<Pair>();
        for (int i = 0; i < n; i++) {
                arr[i] = rnd.nextInt(maxx / 2) + maxx / 2;
        }

        ArrayList<Pair> changes = new ArrayList<Pair>();
        ArrayList<Integer> step = new ArrayList<Integer> ();
        for (int i = l; i <= r; i++) {
            step.add(i);
            step.add(-i);
        }
        if (l == 3) step.add(r - 1);
        step.add(r);
        int count = n;
        int curpos = rnd.nextInt(count);

        do {
            int type = rnd.nextInt(2) + 1;
            changes.add(new Pair(type, curpos));
            if (type == 1) {
                count--;
            } else {
                count++;
            }
            int j = rnd.nextInt(step.size());
            if (curpos + step.get(j) > count) {
                step.remove(step.size() - 1);

                if (l == 3) {
                    step.remove(step.size() - 1);
                    step.add(- r + 1);
                }
                step.add(-r);
            }
            if (curpos + step.get(j) < 0) {
                step.remove(step.size() - 1);
                if (l == 3) {
                    step.remove(step.size() - 1);
                    step.add(r - 1);
                }
                step.add(r);
            }
            while (curpos + step.get(j) < 0 || curpos + step.get(j) > count) {
                j = rnd.nextInt(step.size());
            }
            curpos += step.get(j);
        } while (changes.size() < m);
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Random test with step from " + l + " to " + r);
        print(arr, changes);
    }

    void genTestBoris() throws IOException {
        final int n = 100000;
        final int MAX_X = 10000;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = MAX_X;
        }
        final int k = 100000;
        int start = 0;
        int next = MAX_X;
        int cur = MAX_X;
        ArrayList<Pair> changes = new ArrayList<Pair>();
        for (int i = 0; i < k; i++) {
            if (cur >= 2) {
                changes.add(new Pair(2, start + 1));
                start++;
                cur = (cur + 1) / 2;
            } else {
                changes.add(new Pair(1, start + 2));
                cur += next / 2;
                next = MAX_X + (next + 1) / 2;
            }
        }
        tests.add("../tests/subtask" + subtask + "/" + (tNumber / 10) + (tNumber % 10) + "   n = " + n + ", k = " + changes.size()+
                ". Anti stupid expand test");
        print(arr, changes);
    }

    ArrayList<String> tests;
    void genTestsDesc() throws FileNotFoundException {
        out = new PrintWriter("../tests.desc");
        for (String s : tests) {
            out.println(s);
        }
        out.close();
    }

    public void generate() throws IOException {
        new File("../tests").mkdir();
        new File("../tests/subtask1").mkdir();
        new File("../tests/subtask2").mkdir();
        new File("../tests/subtask3").mkdir();
        new File("../tests/subtask4").mkdir();
        new File("../preliminary").mkdir();

        tNumber = 1;
        tNumberPre = 1;
        tests = new ArrayList<String>();
        genSimple();
        rnd = new Random(313131311);
        subtask = 1;
        genTest1(100, 100);
        genTest2(100, 100);
        genTest3(100);
        genTest4(100);
        genTest5(100, 100);
        genTest6(100, 100, true, 100);
        genTest7(100, 100);
        genTest8(100, 100);
        genTest9(100, 100, 100);
        genTest10(100, 100, true, 100);

        subtask = 2;
        genTest9(MAXN, MAXM, MAXX);
        genRandTestWithStep(MAXN, MAXM, MAXX, 8, 10);
        genRandTestWithStep(MAXN, MAXM, MAXX, 8, 10);
        genRandTestWithStep(MAXN, MAXM, MAXX, 3, 10);
        genRandTestWithStep(MAXN, MAXM, MAXX, 9, 10);

        subtask = 3;
        genTest1(MAXN, MAXX);
        genTest2(MAXN, MAXX);
        genTest3(MAXN);
        genTest4(MAXN);
        genTest5(MAXN, MAXX);


        subtask = 4;
        genTest6(MAXN, MAXX, true, MAXM);
        genTest7(MAXN, MAXX);
        genTest8(MAXN, MAXX);
        genTest10(MAXN, MAXX, true, MAXM);
        genTest10(MAXN, MAXX, false, MAXM);
        genTestBoris();


        genTestsDesc();
    }

    public void run() throws IOException {
        //Locale.setDefault(Locale.US);
        generate();
    }

    static class RandomPermutation {

        public static void shuffle(int[] a) {
            Random rnd = new Random();
            for (int i = a.length - 1; i >= 1; i--) {
                int j = rnd.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

        public static int[] getRandomPermutation(int n) {
            Random rnd = new Random();
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                int j = rnd.nextInt(i + 1);
                res[i] = res[j];
                res[j] = i;
            }
            return res;
        }

        public static int[] getRandomArrangement(int n, int m) {
            Random rnd = new Random();
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
                res[i] = i;
            for (int i = 0; i < m; i++) {
                int j = i + rnd.nextInt(n - i);
                int t = res[i];
                res[i] = res[j];
                res[j] = t;
            }
            return Arrays.copyOf(res, m);
        }

        public static int[] getRandomCombination(int n, int m) {
            int[] res = getRandomArrangement(n, m);
            Arrays.sort(res);
            return res;
        }

        // for small m
        public static int[] getRandomArrangement2(int n, int m) {
            Random rnd = new Random();
            Set<Integer> set = new HashSet<Integer>();
            int[] res = new int[m];
            while (set.size() < m) {
                int x = rnd.nextInt(n);
                if (set.add(x))
                    res[set.size() - 1] = x;
            }
            return res;
        }

    }
}
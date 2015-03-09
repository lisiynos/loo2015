import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.util.Arrays;
import java.util.Random;

public class Tests {
    static int[] MAXN = {50, 5000, 100000};
    static int[] MAX = {100000, 100000, 1000000000};
    int group;

    Random rnd = new Random(239);

    String folder;

    PrintWriter desc;

    public static void main(String[] args) throws FileNotFoundException {
        new Tests().gen();
    }

    public int random(int l, int r) {
        if (r < l)
            return l;

        return l + rnd.nextInt(r - l + 1);
    }

    static int tests = 1;

    public void writeTest(int[] a, int k, String description) {
        try {
            PrintWriter out = new PrintWriter(String.format(folder + "%02d", tests++));

            System.err.println("Writing test " + (tests - 1));

            desc.println(String.format(folder + "%02d", tests - 1) + "\t" + description + " n = " + a.length + ", k = " + k);

            out.println(a.length + " " + k);

            for (int i = 0; i < a.length; i++) {
                out.print(a[i]);
                if (i < a.length - 1) {
                    out.print(" ");
                }
            }
            out.println();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void genRandom(int n, int k) {
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = random(1, MAX[group]);
        }

        writeTest(a, k, "Random test with");
    }

    public void genRandom(int n) {
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = random(1, MAX[group]);
        }

        writeTest(a, random(1, n / 3), "Random test with");
    }

    public void genOneRandom(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = random(1, MAX[group]);
        }

        writeTest(a, 1, "Random test with");
    }

    public void genOneOnPosition(int n, int pos) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = random(1, MAX[group] - 1);
        }
        a[pos] = MAX[group];
        writeTest(a, 1, "Random test with max at " + pos + " and ");
    }

    public void genMaxRandom(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = random(1, MAX[group]);
        }

        writeTest(a, n / 3, "Maximal random test with");
    }

    public void genMax(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = MAX[group];
        }

        writeTest(a, n / 3, "Maximal test with");
    }

    public void antiMaxCover(int n, int k) {
        int[] a = new int[n];
        Arrays.fill(a, 1);
        int len = k - 2 + k + k;
        int pos = (n - len) / 2;

        for (int i = 0; i < k; i++, pos++)
            a[pos] = MAX[group];
        for (int i = 0; i < k - 2; i++, pos++)
            a[pos] = MAX[group] / 2;
        for (int i = 0; i < k; i++, pos++)
            a[pos] = MAX[group];
//            a[i] = (total + k - 1) / k;
        writeTest(a, k, "Anti-greedy test with");
    }

    public void antiMaxCover2(int n, int k) {
        int[] a = new int[n];
        Arrays.fill(a, 1);
        for (int i = 0; i < n - k; i += k)
            if (i % k == 0)
                a[i] = MAX[group];

        int total = k - 1 + MAX[group];
        for (int i = n - 1; i >= n - k; i--)
            a[i] = (total + k - 1) / k;
        writeTest(a, k, "Anti-greedy test with");
    }

    public void antiMaxCover3(int n, int k) {
        int[] a = new int[n];
        Arrays.fill(a, MAX[group] - 1);
        int len = k - 2 + k + k;
        int pos = (n - len) / 2;

        for (int i = 0; i < k; i++, pos++)
            a[pos] = MAX[group];
        for (int i = 0; i < k - 2; i++, pos++)
            a[pos] = MAX[group] / 2;
        for (int i = 0; i < k; i++, pos++)
            a[pos] = MAX[group];
        writeTest(a, k, "Anti-greedy test with");
    }

    public void gen() {
        try{
            desc = new PrintWriter("../tests.desc");
        } catch (IOException e) {
//
        }

        tests = 1;
        folder = "../preliminary/";
        if (!new File(folder).exists())
            new File(folder).mkdir();
        writeTest(new int[]{1, 2, 4, 5, 2, 4, 2, 2, 1, 6}, 2, "Sample test");

        // tests = 1; // TestSys
        folder = "../tests/";
        if (!new File(folder).exists())
            new File(folder).mkdir();

        for (group = 0; group < MAX.length; group++) {
            folder = String.format("../tests/subtask%d/", (group + 1));
            if (!new File(folder).exists())
                new File(folder).mkdir();

            for (int i = 0; i < 3; i++)
                genRandom(MAXN[group]);

            genOneRandom(MAXN[group]);

            if (group != 0) {
                for (int x : new int[]{0, 1, MAXN[group] - 2, MAXN[group] - 1})
                    genOneOnPosition(MAXN[group], x);
            }
            
            for (int i = 0; i < 2; i++) {
                genMaxRandom(MAXN[group]);
            }

            genMax(MAXN[group]);
            genRandom(MAXN[group], (int)(Math.sqrt(MAXN[group])));
            genRandom(MAXN[group], MAXN[group] / 5);
//            antiMaxCover(MAXN[group], random(1, MAXN[group] / 3));
            antiMaxCover(MAXN[group], MAXN[group] / 3);
            antiMaxCover2(MAXN[group], MAXN[group] / 3);
            antiMaxCover3(MAXN[group], MAXN[group] / 5);
            antiMaxCover3(MAXN[group], (int)(Math.sqrt(MAXN[group])));
        }

        desc.close();
    }
}

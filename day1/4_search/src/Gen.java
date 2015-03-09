import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Gen {

    static class URL {
        ArrayList<String> server;
        ArrayList<String> catalog;

        public URL(ArrayList<String> server, ArrayList<String> catalog) {
            super();
            this.server = server;
            this.catalog = catalog;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            URL url = (URL) o;

            if (catalog != null ? !catalog.equals(url.catalog) : url.catalog != null) return false;
            if (server != null ? !server.equals(url.server) : url.server != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = server != null ? server.hashCode() : 0;
            result = 31 * result + (catalog != null ? catalog.hashCode() : 0);
            return result;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(server.get(0));
            for (int i = 1; i < server.size(); i++) {
                sb.append(".");
                sb.append(server.get(i));
            }
            for (String ctlg : catalog) {
                sb.append("/");
                sb.append(ctlg);
            }
            return sb.toString();
        }
    }

    static final Random rand = new Random(556668949239L);
    static final int MAX_CNT_FILTERS = 50000;
    static final int MAX_CNT_URLS = 50000;
    final static String ALPHA = "abcdefghijklmnopqrstuvwxyz";
    final static int LEN = ALPHA.length();
    static int done = 0;
    static ArrayList<URL> filters = new ArrayList<>();
    static ArrayList<URL> urls = new ArrayList<>();

    static ArrayList<String> logger = new ArrayList<>();

    static void print(int numSubtask) throws IOException {
        done++;
        System.err.println(done);
        PrintWriter out;
        out = new PrintWriter(String.format("../tests/subtask%d/%02d",
                numSubtask, done));
        // Collections.shuffle(filters, rand);
        // Collections.shuffle(urls, rand);

        out.println(filters.size() + " " + numSubtask);
        for (URL filter : filters) {
            out.println(filter);
        }

        out.println(urls.size());
        for (URL url : urls) {
            out.println(url);
        }
        logger.add(String.format("../tests/subtask%d/%02d",
                numSubtask, done) + "\t" + "n = " + filters.size() + " k = " + urls.size());
        filters.clear();
        urls.clear();
        out.close();
    }

    static int randFromTo(int l, int r) {
        return l + rand.nextInt(r - l + 1);
    }

    static void genSimple() throws IOException {
        PrintWriter out;
        out = new PrintWriter("../preliminary/01");
        List<String> filters = Arrays.asList("a.bb/c", "bb/c/d");
        List<String> urls = Arrays.asList("a.bb", "bb/c/d", "a.bb/c/d", "bb/c");
        out.println(filters.size() + " " + 0);
        for (String s : filters) {
            out.println(s);
        }
        out.println(urls.size());
        for (String s : urls) {
            out.println(s);
        }
        logger.add("../preliminary/01" + "\t" + "n = " + filters.size() + " k = " + urls.size());
        out.close();
        done++; // TestSys
        out = new PrintWriter("../preliminary/02");
        filters = Arrays.asList("*.bb/c", "*.bb/c/*", "bb/c/*", "bb/c/*");
        urls = Arrays.asList("bb", "bb/c", "bb/c/d", "a.bb", "a.bb/c",
                "a.bb/c/d");
        out.println(filters.size() + " " + 0);
        for (String s : filters) {
            out.println(s);
        }
        out.println(urls.size());
        for (String s : urls) {
            out.println(s);
        }
        logger.add("../preliminary/02" + "\t" + "n = " + filters.size() + " k = " + urls.size());
        out.close();
        done++; // TestSys
    }

    static String genRandomString(int len) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            sb.append(ALPHA.charAt(rand.nextInt(LEN)));
        }
        return sb.toString();
    }

    static URL genRandomURL(int cntServ, int lenServ, int cntCtlg, int lenCtlg) {
        ArrayList<String> serv = new ArrayList<>();
        ArrayList<String> ctlg = new ArrayList<>();
        for (int i = 0; i < cntServ; i++) {
            serv.add(genRandomString(lenServ));
        }
        for (int i = 0; i < cntCtlg; i++) {
            ctlg.add(genRandomString(lenCtlg));
        }
        return new URL(serv, ctlg);
    }

    static URL genRandomDelimStringToURL(String s) {
        ArrayList<Integer> delim = new ArrayList<>();
        int i = 0;
        delim.add(0);
        int pos = 0;
        while (i < s.length()) {
            int t = rand.nextInt(s.length() / 4) + 1;
            if (i < s.length() / 2 && s.length() / 2 < i + t) {
                delim.add(s.length() / 2);
                pos = delim.size();
            }
            if (s.length() / 2 == i + t) {
                delim.add(s.length() / 2);
                pos = delim.size();
                t++;
            }
            if (delim.size() < 4 && i + t < s.length() / 2) {
                delim.add(s.length() / 2);
                pos = delim.size();
                i = s.length() / 2;
            }
            if (i + t < s.length())
                delim.add(i + t);
            i += t;
            if (delim.size() - pos == 5) {
                break;
            }
        }
        delim.add(s.length());
        ArrayList<String> serv = new ArrayList<>();
        ArrayList<String> ctlg = new ArrayList<>();

        for (i = 0; i < pos; i++) {
            serv.add(s.substring(delim.get(i), delim.get(i + 1)));
        }
        for (i = pos; i < delim.size() - 1; i++) {
            ctlg.add(s.substring(delim.get(i), delim.get(i + 1)));
        }
        return new URL(serv, ctlg);
    }

    static ArrayList<String> genStringByNubmer(long num, int len) {
        ArrayList<String> res = new ArrayList<>();
        long MOD = (long) Math.pow(26, len);
        while (num > 0) {
            long cur = num % MOD;
            num /= MOD;
            String s = "";
            while (cur > 0) {
                s += (char) (cur % 26 + 'a');
                cur /= 26;
            }
            if (s.equals("")) {
                s = "zz";
            }
            res.add(s);
        }
        return res;
    }

    static URL genUrl(ArrayList<String> set, int servLen, int ctlgLen, boolean isFilter, boolean notRand) {
        ArrayList<String> serv = new ArrayList<>();
        ArrayList<String> ctlg = new ArrayList<>();
        for (int i = 0; i < servLen; i++) {
            serv.add(set.get(rand.nextInt(set.size())));
        }
        for (int i = 0; i < ctlgLen; i++) {
            ctlg.add(set.get(rand.nextInt(set.size())));
        }
        if (isFilter) {
            if (notRand || rand.nextBoolean()) {
                if (serv.size() == 5) {
                    serv.set(0, "*");
                } else {
                    serv.add(0, "*");
                }
            }
            if (notRand || rand.nextBoolean()) {
                if (ctlg.size() == 5) {
                    ctlg.set(4, "*");
                } else {
                    ctlg.add("*");
                }
            }
        }
        return new URL(serv, ctlg);
    }

    static URL genFilter(URL url, boolean isGr1) {
        ArrayList<String> serv = new ArrayList<>(url.server);
        ArrayList<String> ctlg = new ArrayList<>(url.catalog);
        if (isGr1 || rand.nextBoolean()) {
            int pos = randFromTo(2, 4);
            if (pos > serv.size()) {
                serv.add(0, "*");
            } else {
                pos = serv.size() - pos;
                for (int i = 0; i < pos; i++) {
                    serv.remove(0);
                }
                serv.add(0, "*");
            }
        }
        if (isGr1 || rand.nextBoolean()) {
            int pos = randFromTo(1, 4);
            if (pos > ctlg.size()) {
                ctlg.add("*");
            } else {
                while (ctlg.size() > pos) {
                    ctlg.remove(ctlg.size() - 1);
                }
                ctlg.add("*");
            }
        }
        return new URL(serv, ctlg);
    }

    static ArrayList<URL> uniqieFilter(ArrayList<URL> filters) {
        int si = filters.size();
        HashSet<URL> set = new HashSet<>(filters);
        filters.clear();
        for (URL url : set) {
            filters.add(url);
        }
        System.err.println(si + " " + filters.size());
        return filters;
    }

    public static void main(String[] args) throws IOException {
        new File("../preliminary").mkdir();
        new File("../tests").mkdir();

        genSimple();

        // done = 0; // TestSys

        // First group (1 - 9 test)
        // n, k <= 1000
        // Filters begins and ends *
        new File("../tests/subtask1").mkdir();

        // Test # 1.

        String first = genRandomString(4);
        String second = genRandomString(5);
        for (int len1 = 1; len1 < 5; len1++) {
            for (int len2 = 0; len2 < 4; len2++) {
                for (int mask1 = 0; mask1 < (1 << len1); mask1++) {
                    for (int mask2 = 0; mask2 < (1 << len2); mask2++) {
                        ArrayList<String> serv = new ArrayList<>();
                        ArrayList<String> ctlg = new ArrayList<>();
                        for (int i = 0; i < len1; i++) {
                            if (((1 << i) & mask1) == 0) {
                                serv.add(first);
                            } else {
                                serv.add(second);
                            }
                        }
                        for (int i = 0; i < len2; i++) {
                            if (((1 << i) & mask2) == 0) {
                                ctlg.add(first);
                            } else {
                                ctlg.add(second);
                            }
                        }
                        urls.add(new URL(new ArrayList<>(serv),
                                new ArrayList<>(ctlg)));
                        serv.add(0, "*");
                        ctlg.add("*");
                        filters.add(new URL(serv, ctlg));
                    }
                }
            }
        }
        print(1);

        // Test # 2.
        {
            String s = genRandomString(40);
            for (int i = 0; i < 1000; i++) {
                urls.add(genRandomDelimStringToURL(s));
            }
            for (int i = 0; i < 1000; i++) {
                URL url = genRandomDelimStringToURL(s);
                if (url.server.size() > 1) {
                    url.server.set(0, "*");
                } else {
                    url.server.add(0, "*");
                }
                if (url.catalog.size() > 0) {
                    url.catalog.set(url.catalog.size() - 1, "*");
                } else {
                    url.catalog.add("*");
                }
                filters.add(url);
            }
            print(1);
        }

        // Test # 3.
        {
            String s = genRandomString(3);
            for (int i = 0; i < randFromTo(500, 700); i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                urls.add(new URL(serv, ctlg));
            }
            for (int i = 0; i < randFromTo(666, 777); i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                URL url = new URL(serv, ctlg);
                if (url.server.size() > 1) {
                    url.server.set(0, "*");
                } else {
                    url.server.add(0, "*");
                }
                if (url.catalog.size() > 0) {
                    url.catalog.set(url.catalog.size() - 1, "*");
                } else {
                    url.catalog.add("*");
                }
                filters.add(url);
            }
            for (int i = 0; i < 200; i++) {
                URL url = new URL(new ArrayList<>(urls.get(rand.nextInt(urls
                        .size())).server), new ArrayList<>(urls.get(rand
                        .nextInt(urls.size())).catalog));
                if (url.server.get(0).length() > 1) {
                    url.server.set(0, url.server.get(0).substring(1));
                }
                url.server.add(0, "*");
                if (url.catalog.size() >= 1) {
                    if (url.catalog.get(url.catalog.size() - 1).length() > 1)
                        url.catalog.set(url.catalog.size() - 1, url.catalog.get(url.catalog.size() - 1).substring(0, url.catalog.get(url.catalog.size() - 1).length() - 1));
                }
                url.catalog.add("*");
                filters.add(url);
            }
            filters = uniqieFilter(filters);

            print(1);
        }

        // Test # 4.
        {
            String s = genRandomString(3);
            for (int i = 0; i < randFromTo(500, 700); i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                urls.add(new URL(serv, ctlg));
            }
            for (int i = 0; i < randFromTo(666, 777); i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                URL url = new URL(serv, ctlg);
                if (url.server.size() > 1) {
                    url.server.set(0, "*");
                } else {
                    url.server.add(0, "*");
                }
                if (url.catalog.size() > 0) {
                    url.catalog.set(url.catalog.size() - 1, "*");
                } else {
                    url.catalog.add("*");
                }
                filters.add(new URL(serv, ctlg));
            }
            print(1);
        }

        // Test 5.
        {
            ArrayList<String> set = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                set.add(genRandomString(randFromTo(1, 5)));
            }
            for (int i = 0; i < 1000; i++) {
                urls.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), false, false));
            }
            for (int i = 0; i < 1000; i++) {
                filters.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), true, true));
            }
            filters = uniqieFilter(filters);
            print(1);
        }

        // Test 6.
        {
            ArrayList<String> set = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                set.add(genRandomString(3));
            }
            for (int i = 0; i < 777; i++) {
                urls.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), false, false));
            }
            for (int i = 0; i < 1000; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), true));
            }
            print(1);
        }

        // Test # 7.
        {
            for (int i = 0; i < 888; i++) {
                urls.add(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 4), genStringByNubmer(Math.abs(rand.nextLong()), 3)));
            }
            for (int i = 0; i < 800; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), true));
            }
            for (int i = 0; i < 200; i++) {
                filters.add(genFilter(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 4), genStringByNubmer(Math.abs(rand.nextLong()), 3)), true));
            }
            filters = uniqieFilter(filters);
            print(1);
        }

        // Test # 8.
        {
            for (long id = 0; id < 1000; id++) {
                urls.add(new URL(genStringByNubmer(id * 2 + 1, 1), genStringByNubmer(id * 2, 1)));
            }
            for (int i = 0; i < 1000; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), true));
            }
            filters = uniqieFilter(filters);
            print(1);
        }

        // Test # 9.
        {
            for (int i = 0; i < randFromTo(50, 100); i++) {
                urls.add(genRandomURL(randFromTo(1, 5), 4, randFromTo(0, 5), 4));
            }
            for (int i = 0; i < 1000; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), true));
            }
            filters = uniqieFilter(filters);
            print(1);
        }

        // Second group (10 - 14 test)
        // n, k <= 100000
        // Filter doesn't contain *
        new File("../tests/subtask2").mkdir();

        // Test # 10.
        for (int i = 0; i < MAX_CNT_URLS; i++) {
            urls.add(genRandomURL(3, 1, 3, 1));
        }

        for (int i = 0; i < MAX_CNT_FILTERS; i++) {
            filters.add(genRandomURL(3, 1, 3, 1));
        }

        print(2);

        // Test # 11.
        {
            String s = "" + ALPHA.charAt(rand.nextInt(LEN));
            int cntUrl = randFromTo(MAX_CNT_URLS / 3 * 2, MAX_CNT_URLS);
            for (int i = 0; i < cntUrl; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                urls.add(new URL(serv, ctlg));
            }
            int cntFilter = randFromTo(MAX_CNT_FILTERS / 3 * 2, MAX_CNT_FILTERS);
            for (int i = 0; i < cntFilter; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                filters.add(new URL(serv, ctlg));
            }
            print(2);
        }

        // Test # 12.
        {
            URL url = genRandomURL(3, 1, 2, 2);
            for (int i = 0; i < MAX_CNT_URLS; i++) {
                urls.add(url);
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(url);
            }
            print(2);
        }

        // Test # 13.
        {
            int cntUrl = randFromTo(MAX_CNT_URLS / 3 * 2, MAX_CNT_URLS);
            for (int i = 0; i < cntUrl; i++) {
                urls.add(genRandomURL(randFromTo(1, 5), randFromTo(1, 2),
                        randFromTo(0, 5), randFromTo(1, 2)));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(urls.get(rand.nextInt(urls.size())));
            }
            filters = uniqieFilter(filters);
            print(2);
        }

        // Test # 14.
        {
            int t = randFromTo(5, 25);
            for (int i = 0; i < t; i++) {
                URL url = (rand.nextBoolean() ? genRandomURL(randFromTo(1, 5),
                        randFromTo(1, 3), randFromTo(0, 3), 1)
                        : genRandomURL(randFromTo(1, 3), 1, randFromTo(0, 5),
                        randFromTo(1, 3)));
                for (int j = 0; j < MAX_CNT_URLS / t; j++) {
                    urls.add(url);
                }
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(urls.get(rand.nextInt(urls.size())));
            }
            print(2);
        }

        // Third group (15 - 26 test)
        // n, k <= 100000
        new File("../tests/subtask3").mkdir();

        // Test # 15.
        first = genRandomString(4);

        second = genRandomString(4);

        for (int len1 = 1; len1 < 6; len1++) {
            for (int len2 = 0; len2 < 6; len2++) {
                for (int mask1 = 0; mask1 < (1 << len1); mask1++) {
                    for (int mask2 = 0; mask2 < (1 << len2); mask2++) {
                        ArrayList<String> serv = new ArrayList<>();
                        ArrayList<String> ctlg = new ArrayList<>();
                        for (int i = 0; i < len1; i++) {
                            if (((1 << i) & mask1) == 0) {
                                serv.add(first);
                            } else {
                                serv.add(second);
                            }
                        }
                        for (int i = 0; i < len2; i++) {
                            if (((1 << i) & mask2) == 0) {
                                ctlg.add(first);
                            } else {
                                ctlg.add(second);
                            }
                        }
                        urls.add(new URL(new ArrayList<>(serv),
                                new ArrayList<>(ctlg)));
                        for (int mask = 0; mask < 4; mask++) {
                            ArrayList<String> serv2 = new ArrayList<>(
                                    serv);
                            ArrayList<String> ctlg2 = new ArrayList<>(
                                    ctlg);
                            if (len1 < 5 && ((mask & 1) == 0)) {
                                serv2.add(0, "*");
                            }
                            if (len2 < 5 && (mask & 2) == 0) {
                                ctlg2.add("*");
                            }
                            filters.add(new URL(serv2, ctlg2));
                        }
                    }
                }
            }
        }

        print(3);

        // Test # 16.

        {
            String s = genRandomString(25);
            for (int i = 0; i < MAX_CNT_URLS; i++) {
                urls.add(genRandomDelimStringToURL(s));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                URL url = genRandomDelimStringToURL(s);
                if (rand.nextBoolean()) {
                    if (url.server.size() > 1) {
                        url.server.set(0, "*");
                    } else {
                        url.server.add(0, "*");
                    }
                }
                if (rand.nextBoolean()) {
                    if (url.catalog.size() > 0) {
                        url.catalog.set(url.catalog.size() - 1, "*");
                    } else {
                        url.catalog.add("*");
                    }
                }
                filters.add(url);
            }
            filters = uniqieFilter(filters);
            print(3);
        }

        // Test # 17.
        {
            String s = genRandomString(1);
            int cntUrl = randFromTo((int) (MAX_CNT_URLS / 10 * 8.8888), (int) (MAX_CNT_URLS / 10 * 9.9999));
            for (int i = 0; i < cntUrl; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                urls.add(new URL(serv, ctlg));
            }
            int cntFilter = randFromTo((int) (MAX_CNT_FILTERS / 10 * 6.6666), (int) (MAX_CNT_FILTERS / 10 * 7.7777));
            for (int i = 0; i < cntFilter; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                URL url = new URL(serv, ctlg);
                if (rand.nextBoolean()) {
                    if (url.server.size() > 1) {
                        url.server.set(0, "*");
                    } else {
                        url.server.add(0, "*");
                    }
                }
                if (rand.nextBoolean()) {
                    if (url.catalog.size() > 0) {
                        url.catalog.set(url.catalog.size() - 1, "*");
                    } else {
                        url.catalog.add("*");
                    }
                }
                filters.add(new URL(serv, ctlg));
            }
            print(3);
        }

        // Test # 18.
        {
            String s = genRandomString(1);
            int cntUrl = randFromTo((int) (MAX_CNT_URLS / 10 * 8.8888), (int) (MAX_CNT_URLS / 10 * 9.9999));
            for (int i = 0; i < cntUrl; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                urls.add(new URL(serv, ctlg));
            }
            int cntFilter = randFromTo((int) (MAX_CNT_FILTERS / 10 * 6.6666), (int) (MAX_CNT_FILTERS / 10 * 7.7777));
            for (int i = 0; i < cntFilter; i++) {
                int cntServ = randFromTo(1, 5);
                int cntCtlg = randFromTo(0, 5);
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < cntServ; j++) {
                    serv.add(s);
                }
                for (int j = 0; j < cntCtlg; j++) {
                    ctlg.add(s);
                }
                URL url = new URL(serv, ctlg);
                if (rand.nextBoolean()) {
                    if (url.server.size() > 1) {
                        url.server.set(0, "*");
                    } else {
                        url.server.add(0, "*");
                    }
                }
                if (rand.nextBoolean()) {
                    if (url.catalog.size() > 0) {
                        url.catalog.set(url.catalog.size() - 1, "*");
                    } else {
                        url.catalog.add("*");
                    }
                }
                filters.add(new URL(serv, ctlg));
            }
            for (int i = 0; i < 20000; i++) {
                filters.add(genFilter(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 4), genStringByNubmer(Math.abs(rand.nextLong()), 3)), true));
            }
            filters = uniqieFilter(filters);
            print(3);
        }

        // Test 19.
        {
            ArrayList<String> set = new ArrayList<>();
            for (int i = 0; i < 5; i++) {
                set.add(genRandomString(1));
            }
            for (int i = 0; i < MAX_CNT_URLS; i++) {
                urls.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), false, false));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), true, true));
            }
            print(3);
        }

        // Test 20.
        {
            ArrayList<String> set = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                set.add(genRandomString(1));
            }
            int cntUrl = randFromTo((int) (MAX_CNT_URLS / 10 * 7.7777), (int) (MAX_CNT_URLS / 10 * 9.9999));
            for (int i = 0; i < cntUrl; i++) {
                urls.add(genUrl(set, randFromTo(1, 5), randFromTo(0, 5), false, false));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), false));
            }
            for (int i = 0; i < 10000; i++) {
                filters.add(genFilter(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 4), genStringByNubmer(Math.abs(rand.nextLong()), 3)), true));
            }
            filters = uniqieFilter(filters);
            print(3);
        }

        // Test 21.
        {
            ArrayList<String> set = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                set.add(genRandomString(randFromTo(1, 2)));
            }
            int cntUrl = randFromTo((int) (MAX_CNT_URLS / 10 * 7.7777), (int) (MAX_CNT_URLS / 10 * 9.9999));
            for (int i = 0; i < cntUrl; i++) {
                urls.add(genUrl(set, randFromTo(1, 3), randFromTo(0, 3), false, false));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), false));
            }
            filters = uniqieFilter(filters);
            print(3);
        }

        // Test # 22.
        {
            for (int i = 0; i < MAX_CNT_URLS / 5; i++) {
                urls.add(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 3), genStringByNubmer(Math.abs(rand.nextLong()), 3)));
            }
            for (int i = 0; i < MAX_CNT_FILTERS * 2 / 5; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), false));
            }
            print(3);
        }

        // Test # 23.
        {
            for (long id = 0; id < MAX_CNT_URLS; id++) {
                urls.add(new URL(genStringByNubmer(id * 2 + 1, 1), genStringByNubmer(id * 2, 1)));
            }
            for (int i = 0; i < MAX_CNT_FILTERS; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), false));
            }
            filters = uniqieFilter(filters);
            print(3);
        }

        // Test # 24.
        {
            for (int i = 0; i < MAX_CNT_URLS / 10; i++) {
                urls.add(new URL(genStringByNubmer(Math.abs(rand.nextLong() + 1), 5), genStringByNubmer(Math.abs(rand.nextLong()), 5)));
            }
            for (int i = 0; i < MAX_CNT_FILTERS / 2; i++) {
                filters.add(genFilter(urls.get(rand.nextInt(urls.size())), false));
            }
            print(3);
        }

        // Test # 25.
        {
            for (int i = 0; i < 27; i++) {
                for (int j = 0; j < 26; j++) {
                    for (int k = 0; k < 27; k++) {
                        ArrayList<String> serv = new ArrayList<>();
                        String c = (i == 26) ? "*" : ("" + (char) (i + 'a'));
                        serv.add(c);
                        serv.add("" + (char) (j + 'a'));
                        c = (k == 26) ? "*" : ("" + (char) (k + 'a'));
                        ArrayList<String> ctlg = new ArrayList<>();
                        ctlg.add(c);
                        filters.add(new URL(serv, ctlg));
                    }
                }
            }
            for (int i = 0; i < MAX_CNT_URLS; i++) {
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                serv.add(genRandomString(1));
                for (int j = 0; j < 5; j++) {
                    ctlg.add(genRandomString(j == 0 ? 40 : 1));
                }
                urls.add(new URL(serv, ctlg));
            }
            print(3);
        }

        // Test # 26.
        {
            for (int i = 0; i < 27; i++) {
                for (int j = 0; j < 26; j++) {
                    for (int k = 0; k < 27; k++) {
                        ArrayList<String> serv = new ArrayList<>();
                        String c = (i == 26) ? "*" : ("" + (char) (i + 'a'));
                        serv.add(c);
                        serv.add("" + (char) (j + 'a'));
                        c = (k == 26) ? "*" : ("" + (char) (k + 'a'));
                        ArrayList<String> ctlg = new ArrayList<>();
                        ctlg.add(c);
                        filters.add(new URL(serv, ctlg));
                    }
                }
            }
            for (int i = 0; i < MAX_CNT_URLS; i++) {
                ArrayList<String> serv = new ArrayList<>();
                ArrayList<String> ctlg = new ArrayList<>();
                for (int j = 0; j < 5; j++) {
                    serv.add(genRandomString(1));
                    ctlg.add(genRandomString(j == 0 ? 30 : 1));
                }
                urls.add(new URL(serv, ctlg));
            }

            print(3);
        }
        PrintWriter desc = new PrintWriter("../tests.desc");
        for (String s : logger) {
            desc.println(s);
        }
        desc.close();
    }
}

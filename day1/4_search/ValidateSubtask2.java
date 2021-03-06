import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class ValidateSubtask2 {

    final int MAX_LENGTH = 50;
    final int MAX_SIZE_FILE = 4 * 1024 * 1024;
    final int MAX_N = 50_000;
    final int MAX_K = 50_000;

    public void run() {
        StrictScanner inf = new StrictScanner(System.in);
        int n = inf.nextInt();
        int subtask = inf.nextInt();
        ensure(subtask == 2, "subtask 2");
        inf.nextLine();
        int curSizeFile = Integer.toString(n).length() + 2;
        ensureLimits(n, 1, MAX_N, "n");
        Pattern p = Pattern.compile("^([a-z]+\\.){0,4}([a-z]+)(\\/[a-z]+){0,5}$");
        for (int i = 0; i < n; i++) {
            String s = inf.next();
            inf.nextLine();
            curSizeFile += s.length() + 2;
            ensureLimits(s.length(), 1, MAX_LENGTH, "Length filter " + (i + 1));
            ensure(p.matcher(s).matches(), "Inccorrect Filter at position " + (i + 1));
        }
        int k = inf.nextInt();
        inf.nextLine();
        curSizeFile += Integer.toString(k).length() + 2;
        ensureLimits(k, 1, MAX_K, "k");
        for (int i = 0; i < k; i++) {
            String s = inf.next();
            inf.nextLine();
            curSizeFile += s.length() + 2;
            ensureLimits(s.length(), 1, MAX_LENGTH, "Length URL " + (i + 1));
            ensure(p.matcher(s).matches(), "Inccorrect URL at position " + (i + 1));
        }
        ensureLimits(curSizeFile, 1, MAX_SIZE_FILE, "File size");
        inf.close();
    }

    public static void main(String[] args) {
        new ValidateSubtask2().run();
    }

    public class StrictScanner {
        private final BufferedReader in;
        private String line = "";
        private int pos;
        private int lineNo;

        public StrictScanner(InputStream source) {
            in = new BufferedReader(new InputStreamReader(source));
            nextLine();
        }

        public void close() {
            ensure(line == null, "Extra data at the end of file");
            try {
                in.close();
            } catch (IOException e) {
                throw new AssertionError("Failed to close with " + e);
            }
        }

        public void nextLine() {
            ensure(line != null, "EOF");
            ensure(pos == line.length(), "Extra characters on line " + lineNo);
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new AssertionError("Failed to read line with " + e);
            }
            pos = 0;
            lineNo++;
        }

        public String next() {
            ensure(line != null, "EOF");
            ensure(line.length() > 0, "Empty line " + lineNo);
            if (pos == 0)
                ensure(line.charAt(0) > ' ', "Line " + lineNo
                        + " starts with whitespace");
            else {
                ensure(pos < line.length(), "Line " + lineNo + " is over");
                ensure(line.charAt(pos) == ' ', "Wrong whitespace on line "
                        + lineNo);
                pos++;
                ensure(pos < line.length(), "Line " + lineNo + " is over");
                ensure(line.charAt(0) > ' ', "Line " + lineNo
                        + " has double whitespace");
            }
            StringBuilder sb = new StringBuilder();
            while (pos < line.length() && line.charAt(pos) > ' ')
                sb.append(line.charAt(pos++));
            return sb.toString();
        }

        public int nextInt() {
            String s = next();
            ensure(s.length() == 1 || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Integer.parseInt(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }

        public long nextLong() {
            String s = next();
            ensure(s.length() == 1 || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Long.parseLong(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }

        public double nextDouble() {
            String s = next();
            ensure(s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0',
                    "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+', "Extra leading '+' in number " + s
                    + " on line " + lineNo);
            try {
                return Double.parseDouble(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line "
                        + lineNo);
            }
        }
    }

    void ensure(boolean b, String message) {
        if (!b) {
            throw new AssertionError(message);
        }
    }

    void ensureLimits(long n, long from, long to, String name) {
        ensure(from <= n && n <= to, name + " must be from " + from + " to "
                + to);
    }

    void ensureLimits(int n, int from, int to, String name) {
        ensure(from <= n && n <= to, name + " must be from " + from + " to "
                + to);
    }

    void ensureString(String s, String alph, String text) {
        for (int i = 0; i < s.length(); i++) {
            ensure(alph.indexOf(s.charAt(i)) != -1, text);
        }
    }

}

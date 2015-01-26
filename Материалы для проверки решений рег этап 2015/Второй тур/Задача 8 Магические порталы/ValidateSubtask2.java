import java.io.*;

public class ValidateSubtask2 {

	final int MIN_N = 2, MAX_N = 300;

	public void run() {
		StrictScanner inf = new StrictScanner(System.in);
		int n = inf.nextInt(), p = inf.nextInt();
		inf.nextLine();

		ensureLimits(n, MIN_N, MAX_N, "N");
		ensureLimits(p, 0, 0, "P");

		char[][] graph = new char[n][];
		for (int i = 0; i < n; i++) {
			String line = inf.next();
			inf.nextLine();
			
			ensure(line.length() == n, String.format(
					"Line #%d has wrong length %d, but N is %d", i + 1,
					line.length(), n));
			graph[i] = line.toCharArray();
		}

		for (int i = 0; i < n; i++) {
			ensure(graph[i][i] == '.', "Element [" + (i + 1) + "][" + (i + 1)
					+ "] should be \'.\', but was " + graph[i][i]);

			for (int j = i + 1; j < n; j++) {
				ensure(graph[i][j] == '+' || graph[i][j] == '-', "Element ["
						+ (i + 1) + "][" + (j + 1)
						+ "] should be \'+\' or \'-\', but was " + graph[i][j]);

				ensure(graph[j][i] == '+' || graph[j][i] == '-', "Element ["
						+ (j + 1) + "][" + (i + 1)
						+ "] should be \'+\' or \'-\', but was " + graph[j][i]);

				ensure(graph[i][j] != graph[j][i], "Elements [" + (i + 1)
						+ "][" + (j + 1) + "] and [" + (j + 1) + "][" + (i + 1)
						+ "] cannot be equal, but they are");
			}
		}

		inf.close();
	}

	public static void main(String[] args) {
		new Validate().run();
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

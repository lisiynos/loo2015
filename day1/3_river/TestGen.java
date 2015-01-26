import java.io.*;
import java.util.*;

public class TestGen {
	FastScanner in;
	PrintWriter out;

	void solve() {
		final int n = 100000;
		final int MAX_X = 10000;
		out.println(n);
		for (int i = 0; i < n; i++) {
			out.print(MAX_X);
			out.print(i == n - 1 ? "\n" : " ");
		}
		final int k = 100000;
		out.println(k);
		int start = 0;
		int next = MAX_X;
		int cur = MAX_X;
		for (int i = 0; i < k; i++) {
			if (cur >= 2) {
				out.println("2 " + (start + 1));
				start++;
				cur = (cur + 1) / 2;
			} else {
				out.println("1 " + (start + 2));
				cur += next / 2;
				next = MAX_X + (next + 1) / 2;
			}
		}
	}

	void run() {
		try {
			out = new PrintWriter(new File("river.in"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new TestGen().run();
	}
}
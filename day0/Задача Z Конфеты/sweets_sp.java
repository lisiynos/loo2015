import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class sweets_sp implements Runnable {
	public static void main(String[] args) {
		new Thread(new sweets_sp()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "sweets";
	
	int ITER = 1000;

	void solve() {
		long n = nextLong();
		long a = nextLong();
		long b = nextLong();
		long c = nextLong();
/*		if (a < b) {
			long t = a; a = b; b = t;
		}
		if (a < c) {
			long t = a; a = c; c = t;
		}
		if (b < c) {
			long t = c; c = b; b = t;
		}
*/
		BigInteger ABC = BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).multiply(BigInteger.valueOf(c));
		
		long fa = (n / 3) / a * a;
		
		BigInteger ans = BigInteger.ZERO;
		long bestx = 0;
		long besty = 0;
		long bestz = 0;
		for (int i = -ITER; i <= ITER; i++) {
			long x = fa + i * a;
			if (x <= 0 || x > n) continue;
			long rest = n - x;
			long fb = (rest / 2) / b * b;
			for (int j = -ITER; j <= ITER; j++) {
				long y = fb + j * b;
				if (y <= 0 || y > n) continue;
				long z = (n - x - y) / c * c;
				BigInteger tans = BigInteger.valueOf(x).multiply(BigInteger.valueOf(y)).multiply(BigInteger.valueOf(z)).divide(ABC);
				if (tans.compareTo(ans) > 0) {
					ans = tans;
					bestx = x;
					besty = y;
					bestz = z;
				}
			}
		}
		
//		out.println(ans);
		out.println(bestx + " " + besty + " " + bestz);
		
	}
}

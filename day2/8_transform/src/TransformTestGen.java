import java.io.*;
import java.util.*;

public class TransformTestGen {

	final public static int MAX_N = 2_000;
	final static Random rng = new Random(TransformTestGen.class.getSimpleName()
			.hashCode());

	public static void main(String[] args) {
		new TransformTestGen().generate();
	}

	PrintWriter out;
	String dirName = "";
	boolean fullOutput;
	int countTests;
	List<String> descriptions = new ArrayList<>();

	void generate() {
		new File("../tests.desc").delete();

		this.countTests = 0;
		generateSamples();

		// this.countTests = 0; // TestSys
		generateSubtask1();
		generateSubtask2();
		generateSubtask3();
		generateSubtask4();
	}

	void setDirectory(String name) {
		this.dirName = "../" + name;
		File folder = new File(this.dirName);
		if (!folder.exists()) {
			folder.mkdirs();
		}
	}

	void setFullOutput(boolean fullOutput) {
		this.fullOutput = fullOutput;
	}

	private void generateSamples() {
		setDirectory("preliminary");
		setFullOutput(false);
		boolean[][] graph = new boolean[][] {
				new boolean[] { false, false, true, true, true },
				new boolean[] { true, false, true, true, true },
				new boolean[] { false, false, false, true, false },
				new boolean[] { false, false, false, false, true },
				new boolean[] { false, false, true, false, false }, };
		printTest(graph, "sample test #1");

		setFullOutput(true);
		graph = new boolean[][] {
				new boolean[] { false, false, true, true, true },
				new boolean[] { true, false, true, true, true },
				new boolean[] { false, false, false, true, false },
				new boolean[] { false, false, false, false, true },
				new boolean[] { false, false, true, false, false }, };
		printTest(graph, "sample test #2");
	}

	private void generateSubtask1() {
		setDirectory("tests/subtask1");
		setFullOutput(false);

		{
			printAcyclic(2);

			printAcyclic(3);
			printOneSCC(3);

			printAcyclic(4);
			printTest(randomGraphFromSCCSizes(3, 1), "source SCC size=3");
			printTest(randomGraphFromSCCSizes(1, 3), "source SCC size=1");
			printOneSCC(4);

			printAcyclic(6);
			printTest(randomGraphFromSCCSizes(1, 4, 1),
					"sink and source both of size 1");
			printTest(randomGraphFromSCCSizes(1, 1, 4), "source of size 1");
			printTest(randomGraphFromSCCSizes(4, 1, 1), "sink of size 1");
			printOneSCC(6);
		}

		{
			int n = 50;
			printOneSCC(n);
			printAcyclic(n);
			printTest(almostAcyclic(n), "almost acyclic graph");

			printTest(randomGraphFromSCCSizes(n / 2, n / 2), "2 large SCCs");
			printTest(randomGraphFromSCCSizes(repeat(5, 10)),
					"10 SCCs, 5 vertices each");

			printTest(randomGraphFromSCCSizes(randomArray(50)),
					"random SCC sizes");
			printTest(randomGraphFromSCCSizes(1, 1, n - 2),
					"first two components have size 1");
		}
	}

	private void generateSubtask2() {
		setDirectory("tests/subtask2");
		setFullOutput(false);

		int n = 300;
		printAcyclic(n);
		printOneSCC(n);
		printTest(almostAcyclic(n), "almost acyclic graph");

		printTest(randomGraphFromSCCSizes(1, 1, n - 2),
				"first two components have size 1 + one large");
		int[] degs = randomArray(n - 2);
		printTest(randomGraphFromSCCSizes(concat(new int[] { 1, 1 }, degs)),
				"first two components have size 1 + random sizes");

		int[] d = compress(randomArray(n), 10);
		printTest(randomGraphFromSCCSizes(d), "30 random components");
		d = compress(randomArray(n), 50);
		printTest(randomGraphFromSCCSizes(d), "50 random components");
		d = randomArray(n);
		printTest(randomGraphFromSCCSizes(d), "random components");

		printTest(randomGraphFromSCCSizes(n / 2, n / 2), "2 large SCCs");
		printTest(randomGraphFromSCCSizes(repeat(3, n / 3)), "N/3 triangles");
		printTest(randomGraphFromSCCSizes(repeat(5, n / 5)),
				"N/5 SCCs of size 5");

		d = randomArray(n - 2);
		printTest(
				randomGraphFromSCCSizes(concat(new int[] { 1 }, d,
						new int[] { 1 })), "source and sink both have size 1");
		d = randomArray(n - 2);
		printTest(
				randomGraphFromSCCSizes(concat(new int[] { 1 },
						new int[] { 1 }, d)), "first 2 SCCs have size 1");
		d = randomArray(n - 1);
		printTest(randomGraphFromSCCSizes(concat(new int[] { 1 }, d)),
				"source has size 1");

		d = randomArray(n / 2);
		printTest(
				randomGraphFromSCCSizes(concat(repeat(1, n / 2),
						new int[] { n / 2 })),
				"n/2 SCCs of size1 + 1 scc of size n/2");
		printTest(randomGraphFromSCCSizes(concat(repeat(1, n / 2), d)),
				"n/2 SCCs of size1 + random");

	}

	private void generateSubtask3() {
		setDirectory("tests/subtask3");
		setFullOutput(false);
		int[] d;
		int n;

		{
			n = 2000;
			printAcyclic(n);
			printOneSCC(n);
		}

		{
			n = 500;
			printTest(almostAcyclic(n), "almost acyclic graph");

			d = compress(randomArray(n), 4);
			printTest(randomGraphFromSCCSizes(d), "n/4=500 random components");
			d = compress(randomArray(n), 50);
			printTest(randomGraphFromSCCSizes(d), "n/50=40 random components");
			d = compress(randomArray(n), 400);
			printTest(randomGraphFromSCCSizes(d), "n/400=5 random components");

			n = 2000;
			d = compress(randomArray(n), 10);
			printTest(randomGraphFromSCCSizes(d), "n/10=200 random components");
		}

		{
			n = 500;
			printTest(
					randomGraphFromSCCSizes(concat(repeat(1, n / 2),
							new int[] { n / 2 })),
					"n/2 SCCs of size 1 + 1 scc of size n/2");

			d = randomArray(n / 2);
			printTest(randomGraphFromSCCSizes(concat(repeat(1, n / 2), d)),
					"n/2 SCCs of size 1 + random");
		}
		{
			d = new int[n / 4];
			Arrays.fill(d, 3);
			for (int i = 3 * n / 4; i < n; i++) {
				int pos = rng.nextInt(d.length);
				d[pos]++;
			}
			printTest(randomGraphFromSCCSizes(d), "random small SCCs");
		}

		{
			n = 2000;
			int t = n / 4 + rng.nextInt(n / 2);
			printTest(randomGraphFromSCCSizes(t, n - t), "2 large SCCs");

		}

		{
			n = 2000;
			d = randomArray(n - 2);
			printTest(
					randomGraphFromSCCSizes(concat(new int[] { 1 },
							new int[] { 1 }, d)), "first 2 SCCs have size 1");

		}
		{
			n = 200;
			d = randomArray(n - 1);
			printTest(randomGraphFromSCCSizes(concat(new int[] { 1 }, d)),
					"source has size 1");
			d = randomArray(n - 1);
			printTest(randomGraphFromSCCSizes(concat(d, new int[] { 1 })),
					"sink has size 1");
		}
	}

	void generateSubtask4() {
		setDirectory("tests/subtask4");
		setFullOutput(true);

		printTest(new String[] { ".---+-", "+.+-++", "+-.+--", "++-.++",
				"--+-.+", "+-+--." }, "small handy testcase");

		// random small tests with 1 SCC
		for (int n : new int[] { 3, 4, 6, 6, 6, 7, 8, 9, 10, 12}) {
			printOneSCC(n);
		}
		printAcyclic(MAX_N);
		printOneSCC(MAX_N);

		int n;
		int[] d;

		{
			n = 200;
			// almost acyclic 1 SCC graph
			printTest(almostAcyclic(n), "almost acyclic graph");
			// some random edges reversals
			printOneSCC(n);
			printTest(acyclicRandomSwaps(n, 1), "acyclic + 1 random swaps");
			printTest(acyclicRandomSwaps(n, 2), "acyclic + 2 random swaps");
			printTest(acyclicRandomSwaps(n, 10), "acyclic + 10 random swaps");
			printTest(joinN(almostAcyclic(n / 2), almostAcyclic(n / 2)),
					"2 almost acyclic SCCs");

			n = 2000;
			printTest(acyclicRandomSwaps(n, 5), "acyclic + 5 random swaps");
			printTest(acyclicRandomSwaps(n, 50), "acyclic + 50 random swaps");
		}

		{
			n = 2000;
			printTest(trickySCC(n), "1 tricky SCC");
			int sz = rng.nextInt(n / 2) + n / 4;
			printTest(trickySCC(sz, n - sz), "2 tricky SCCs");
			
			n = 300;
			printTest(trickySCC(n / 2, n / 2), "2 tricky equal SCCs");
			printTest(randomGraphFromSCCSizes(repeat(3, n / 3)),
					"n/3 triangles");
		}

		{
			n = 300;
			d = randomArray(n - 1);
			printTest(randomGraphFromSCCSizes(concat(new int[] { 1 }, d)),
					"source has size 1");

			d = randomArray(n - 2);
			printTest(
					randomGraphFromSCCSizes(concat(new int[] { 1 }, d,
							new int[] { 1 })),
					"source and sink both have size 1");
			
			n = 2000;
			d = randomArray(n - 2);
			printTest(
					randomGraphFromSCCSizes(concat(new int[] { 1 },
							new int[] { 1 }, d)), "first 2 SCCs have size 1");
		}
	}

	boolean[][] trickySCC(int... sizes) {
		int n = 1;
		for (int s : sizes) {
			n += s - 1;
		}

		int first = 0;
		boolean[][] graph = new boolean[n][n];
		for (int i = 0; i < sizes.length; i++) {
			int last = first + sizes[i] - 1;

			for (int x = first; x <= last; x++) {
				for (int y = x + 1; y <= last; y++) {
					if (x == first && y == last) {
						graph[y][x] = true;
					} else {
						graph[x][y] = true;
					}
				}
			}

			first = last;
		}

		if (sizes.length > 1) {
			graph[first][0] = true;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!graph[i][j] && !graph[j][i]) {
					graph[i][j] = true;
				}
			}
		}
		return graph;
	}

	boolean[][] joinN(boolean[][]... graphs) {
		if (graphs.length == 1) {
			return graphs[0];
		}
		return joinTwo(joinN(Arrays.copyOf(graphs, graphs.length - 1)),
				graphs[graphs.length - 1]);
	}

	boolean[][] joinTwo(boolean[][] graph1, boolean[][] graph2) {
		int n = graph1.length + graph2.length;
		boolean[][] graph = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (i < graph1.length) {
					if (j < graph1.length) {
						graph[i][j] = graph1[i][j];
					} else {
						graph[i][j] = true;
					}
				} else if (j >= graph1.length) {
					graph[i][j] = graph2[i - graph1.length][j - graph1.length];
				}
			}
		}
		return graph;
	}

	private boolean[][] acyclicRandomSwaps(int n, int k) {
		int[] topSort = randomPermutation(n);
		boolean[][] graph = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				graph[topSort[i]][topSort[j]] = true;
			}
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			do {
				u = rng.nextInt(n);
				v = rng.nextInt(n);
			} while (u == v);
			graph[u][v] = !graph[u][v];
			graph[v][u] = !graph[v][u];
		}
		return graph;
	}

	int[] compress(int[] a, int k) {
		int[] b = new int[(a.length + k - 1) / k];
		for (int i = 0; i < b.length; i++) {
			for (int j = i * k; j < (i + 1) * k && j < a.length; j++) {
				b[i] += a[j];
			}
		}
		return b;
	}

	int[] concat(int[]... arrays) {
		int len = 0;
		for (int[] a : arrays) {
			len += a.length;
		}
		int[] result = new int[len];
		len = 0;
		for (int[] a : arrays) {
			for (int i = 0; i < a.length; i++) {
				result[i + len] = a[i];
			}
			len += a.length;
		}
		return result;
	}

	private void printOneSCC(int size) {
		printTest(randomSCC(size), "strongly connected");
	}

	void printAcyclic(int size) {
		printTest(randomGraphFromSCCSizes(repeat(1, size)), "acyclic");
	}

	int[] repeat(int k, int times) {
		int[] a = new int[times];
		Arrays.fill(a, k);
		return a;
	}

	int[] randomArray(int sum) {
		List<Integer> list = new ArrayList<Integer>();
		int cur = 1;
		for (int i = 1; i < sum; i++) {
			if (rng.nextBoolean()) {
				cur++;
			} else {
				list.add(cur);
				cur = 1;
			}
		}
		list.add(cur);
		int[] ret = new int[list.size()];
		for (int i = 0; i < list.size(); i++) {
			ret[i] = list.get(i);
			if (ret[i] == 2) {
				ret[i]--;
				ret[(i + 1) % ret.length]++;
			}
		}
		if (ret[0] == 2) {
			ret[0] = 1;
		}
		return ret;
	}

	boolean[][] almostAcyclic(int n) {
		int[] topSort = randomPermutation(n);
		boolean[][] graph = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (i == 0 && j == n - 1) {
					graph[topSort[j]][topSort[i]] = true;
				} else {
					graph[topSort[i]][topSort[j]] = true;
				}
			}
		}
		return graph;
	}

	boolean[][] randomGraphFromSCCSizes(int... sizes) {
		int n = 0;
		for (int s : sizes) {
			n += s;
		}

		boolean[][] graph = new boolean[n][n];
		int[] topSort = randomPermutation(n);
		int sum = 0;
		for (int comp = 0; comp < sizes.length; comp++) {
			boolean[][] scc = randomSCC(sizes[comp]);

			for (int i = 0; i < sizes[comp]; i++) {
				for (int j = 0; j < sizes[comp]; j++) {
					graph[topSort[i + sum]][topSort[j + sum]] = scc[i][j];
				}
			}
			for (int i = 0; i < sum; i++) {
				for (int j = sum; j < sum + sizes[comp]; j++) {
					graph[topSort[i]][topSort[j]] = true;
				}
			}
			sum += sizes[comp];
		}
		return graph;
	}

	private boolean[][] randomSCC(int n) {
		if (n == 2) {
			throw new IllegalArgumentException("No SCCs with 2 vertices exist");
		}
		int[] hamCycle = randomPermutation(n);
		boolean[][] scc = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			int from = hamCycle[i], to = hamCycle[(i + 1 == n) ? 0 : (i + 1)];
			scc[from][to] = true;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (scc[i][j] || scc[j][i]) {
					continue;
				}

				boolean edge = rng.nextBoolean();
				scc[i][j] = edge;
				scc[j][i] = !edge;
			}
		}
		return scc;
	}

	int[] randomPermutation(int size) {
		int[] a = new int[size];
		for (int i = 0; i < size; i++) {
			int pos = rng.nextInt(i + 1);
			a[i] = a[pos];
			a[pos] = i;
		}
		return a;
	}

	int randRange(int from, int to) {
		return from + rng.nextInt(to - from + 1);
	}

	private void printTest(String[] s, String desc) {
		int n = s.length;
		boolean[][] graph = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = s[i].charAt(j) == '+';
			}
		}
		printTest(graph, desc);
	}

	void printTest(boolean[][] graph, String desc) {
		try {
			countTests++;
			String fileName = dirName + "/";
			fileName += String.format("%02d", countTests);
			out = new PrintWriter(fileName);

			int n = graph.length;
			out.println(n + " " + (fullOutput ? 1 : 0));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) {
						out.print('.');
					} else {
						out.print(graph[i][j] ? '+' : '-');
					}
				}
				out.println();
			}

			appendDescription(fileName, "N = " + n + ", " + desc);
			System.out.println("Done printing test " + fileName.substring(3));
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private void appendDescription(String fileName, String desc) {
		try (FileWriter fw = new FileWriter("../tests.desc", true);
				PrintWriter out = new PrintWriter(fw)) {
			out.println(fileName + "   " + desc);
		} catch (IOException e) {
			System.err.println("Could not append test description");
		}
	}
}

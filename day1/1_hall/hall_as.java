import java.io.*;
import java.util.*;

public class hall_as {
    public static void main(String[] s) throws IOException {
        new hall_as().run();
    }

    void run() throws IOException {
        Scanner in = new Scanner(new File("hall.in"));
        PrintWriter out = new PrintWriter(new File("hall.out"));

        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();

        long ans = 0;
        for (int x = 1; x <= d / 2 && x * x <= b; x++) {
            int miny = x;
            if ((c + 1) / 2 - x > miny) {
                miny = (c + 1) / 2 - x;
            }
            if ((a + x - 1) / x > miny) {
                miny = (a + x - 1) / x;
            }
            int maxy = d / 2 - x;
            if (b / x < maxy) {
                maxy = b / x;
            }
            if (maxy >= miny) {
                ans += maxy - miny + 1;
            }
        }
        out.println(ans);

        in.close();
        out.close();
    }
}
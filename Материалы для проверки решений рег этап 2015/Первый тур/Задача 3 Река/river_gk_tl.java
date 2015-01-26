import java.io.*;
import java.util.*;

public class river_gk_tl {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();
        in.nextInt(); // ignore subtask
        int l = 0;
        Node root = new Node(0, (1L << 31));
        Segment segment = null;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int d = in.nextInt();
            root.add(segment = new Segment(l, d, segment));
            sum += d * (int) d;
            l += d;
        }
        out.println(sum);

        int k = in.nextInt();
        for (int i = 0; i < k; i++) {
            int e = in.nextInt();
            int v = in.nextInt() - 1;
            Segment s = root.remove(v);
            sum -= s.d * (int) s.d;
            if (e == 1) {
                if (s.prev == null) {
                    sum -= s.next.d * (int) s.next.d;
                    s.next.l = s.l;
                    s.next.d += s.d;
                    s.next.prev = null;
                    root.remove(v);
                    root.add(s.next);
                    sum += s.next.d * (int) s.next.d;
                } else if (s.next == null) {
                    sum -= s.prev.d * (int) s.prev.d;
                    s.prev.d += s.d;
                    s.prev.next = null;
                    sum += s.prev.d * (int) s.prev.d;
                } else {
                    sum -= s.prev.d * (int) s.prev.d + s.next.d * (int) s.next.d;
                    s.prev.d += s.d / 2;
                    s.prev.next = s.next;
                    s.next.prev = s.prev;
                    root.remove(v);
                    s.next.d += s.d / 2 + s.d % 2;
                    s.next.l = s.l + s.d / 2;
                    root.add(s.next);
                    sum += s.prev.d * (int) s.prev.d + s.next.d * (int) s.next.d;
                }
            } else {
                Segment next = s.next;
                Segment s2 = new Segment(s.l + s.d / 2, s.d / 2 + s.d % 2, s);
                s.d /= 2;
                s2.next = next;
                if (next != null) {
                    next.prev = s2;
                }
                root.add(s);
                root.add(s2);
                sum += s.d * (int) s.d + s2.d * (int) s2.d;
            }
            out.println(sum);
        }
    }

    class Segment {
        int l, d;
        Segment next, prev;

        Segment(int l, int d, Segment prev) {
            this.l = l;
            this.d = d;
            this.prev = prev;
            if (prev != null) {
                prev.next = this;
            }
        }
    }

    class Node {
        long l, d;
        int c;
        Node left, right;
        Segment s;

        Node(long l, long d) {
            this.l = l;
            this.d = d;
        }

        void add(Segment s) {
            c++;
            if (d == 1) {
                this.s = s;
                return;
            }
            if (s.l < l + d / 2) {
                if (left == null) {
                    left = new Node(l, d / 2);
                }
                left.add(s);
            } else {
                if (right == null) {
                    right = new Node(l + d / 2, d / 2);
                }
                right.add(s);
            }
        }

        Segment remove(int index) {
            c--;
            if (d == 1) {
                return s;
            }
            int cl = left == null ? 0 : left.c;
            if (index < cl) {
                return left.remove(index);
            } else {
                return right.remove(index - cl);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("river.in"));
        out = new PrintWriter("river.out");

        new river_gk_tl().run();

        in.close();
        out.close();
    }
}

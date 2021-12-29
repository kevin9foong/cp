import java.util.*;

public class bfailed {
    private static List<Range> ranges;
    private static List<Range> ans;

    // some bug in this
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            ranges = new ArrayList<>();
            ans = new LinkedList<>();
            long n = sc.nextLong();
            for (long i = 0; i < n; i++) {
                ranges.add(new Range(sc.nextLong(), sc.nextLong()));
            }
            ranges.remove(new Range(1, n));
            solve(1, n);
            for (Range answer : ans) {
                System.out.println(answer);
            }
        }
    }

    static void solve(long l, long r) {
        // all 1 - n exactly once, check if l is being used
        long d = -1; // will never be -1 since n >= 1
        for (Range ran : ranges) {
            if (ran.l == l && ran.r < r) {
                d = ran.r + 1;
            }
        }
        if (d != -1) {
            // been cut into half
            // 1 - (d - 1) must exist based on prev for loop
            ans.add(new Range(l, r, d));
            ranges.remove(new Range(1, d - 1));
            solve(l, d - 1);

            if (ranges.contains(new Range(d + 1, r))) {
                ranges.remove(new Range(d + 1, r));
                solve(d + 1, r);
            }
        } else {
            // l is used
            ans.add(new Range(l, r, l));
            if (ranges.contains(new Range(l + 1, r))) {
                ranges.remove(new Range(l + 1, r));
                solve(l + 1, r);
            }
        }
    }

    public static class Range {
        long l;
        long r;
        long ans;
        public Range(long l, long r) {
            this.l = l;
            this.r = r;
        }

        public Range(long l, long r, long ans) {
            this.l = l;
            this.r = r;
            this.ans = ans;
        }

        @Override
        public boolean equals(Object other) {
            if (other instanceof Range) {
                Range o = (Range) other;
                if (o.l == this.l && o.r == this.r) {
                    return true;
                }
            }
            return false;
        }

        @Override
        public String toString() {
            return l + " " + r + " " + ans;
        }
//        public long getLen() {
//            return r - l + 1;
//        }
    }
}

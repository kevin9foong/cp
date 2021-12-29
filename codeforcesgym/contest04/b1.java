import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class b1 {
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int t = fs.nextInt();
        for (int tt = 0; tt < t; tt++) {
            int n = fs.nextInt();
            TreeSet<Integer> ts = new TreeSet<>();
            for (int i = 1; i <= n; i++) {
                ts.add(i);
            }
            Range[] ranges = new Range[n]; // must have n ranges since have n selections (1 to 1)
            for (int i = 0; i < n; i++) {
                ranges[i] = new Range(fs.nextInt(), fs.nextInt());
            }
            Arrays.sort(ranges); // sort by length
            for (Range r : ranges) {
                r.ans = ts.floor(r.r);
                ts.remove(r.ans);
                out.println(r);
            }
            out.println();
        }
        out.close();
    }

    public static class Range implements Comparable<Range> {
        int l, r, ans;
        public Range(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public int getLength() {
            return r - l + 1; // since inclusive of l and r
        }

        @Override
        public String toString() {
            return l + " " + r + " " + ans;
        }

        @Override
        public int compareTo(Range o) {
            if (this.getLength() > o.getLength()) {
                // larger
                return 1;
            } else if (this.getLength() < o.getLength()) {
                // smaller
                return -1;
            } else {
                return 0;
            }
        }
    }
}

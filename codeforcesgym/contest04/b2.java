import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

public class b2 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            long t = sc.nextInt();
            while (t-- > 0) {
                HashMap<Long, Long> collided = new HashMap<>();
                PriorityQueue<Range> ranges = new PriorityQueue<>((o1, o2) -> {
                    if (o1.getLen() < o2.getLen()) {
                        return 1;
                    } else if (o1.getLen() > o2.getLen()) {
                        return -1;
                    } else {
                        return 0;
                    }
                });
                long n = sc.nextInt();
                while (n-- > 0) {
                    long l = sc.nextInt();
                    long r = sc.nextInt();
                    for (long i = l; i < r + 1; i++) {
                        collided.put(i, collided.getOrDefault(i, 0L) + 1);
                    }
                    ranges.add(new Range(l, r));
                }

                while (!ranges.isEmpty()) {
                    long chosen = -1;
                    Range r = ranges.poll();
                    for (long i = r.l; i < r.r + 1; i++) {
                        long collisions = collided.get(i);
                        if (collisions == 1) {
                            chosen = i;
                        }
                        collided.put(i, collided.getOrDefault(i, 1L) - 1);
                    }
                    System.out.println(r.l + " " + r.r + " " + chosen);
                }
                System.out.println();
            }
        }

        public static class Range {
            long l;
            long r;
            public Range(long l, long r) {
                this.l = l;
                this.r = r;
            }

            public long getLen() {
                return r - l + 1;
            }
        }
}

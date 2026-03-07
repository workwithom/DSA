import java.util.*;

class ExpectAndMin {

    static class Ball {
        int val;
        int idx;

        Ball(int v, int i) {
            val = v;
            idx = i;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int q = sc.nextInt();

        Ball[] balls = new Ball[n];

        for (int i = 0; i < n; i++) {
            balls[i] = new Ball(sc.nextInt(), i + 1);
        }

        Arrays.sort(balls, (a, b) -> Integer.compare(a.val, b.val));

        StringBuilder out = new StringBuilder();

        for (int i = 0; i < q; i++) {

            int k = sc.nextInt();

            HashSet<Integer> removed = new HashSet<>();

            for (int j = 0; j < k; j++) {
                removed.add(sc.nextInt());
            }

            for (int j = 0; j < n; j++) {
                if (!removed.contains(balls[j].idx)) {
                    out.append(balls[j].val).append("\n");
                    break;
                }
            }
        }

        System.out.print(out);
    }
}
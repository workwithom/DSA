import java.util.*;

public class Main {

    static int signalTowers(int n, int k, List<Integer> positions) {
        if (k <= 1 || n == 0) return 0;

        Collections.sort(positions);

        long low = 0;
        long high = (long) positions.get(n - 1) - positions.get(0);
        long best = 0;

        while (low <= high) {
            long mid = low + (high - low) / 2;

            if (canPlace(positions, n, k, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int) best;
    }

    private static boolean canPlace(List<Integer> positions, int n, int k, long dist) {
        int count = 1;
        long lastPos = positions.get(0);

        for (int i = 1; i < n; i++) {
            if ((long) positions.get(i) - lastPos >= dist) {
                count++;
                lastPos = positions.get(i);
                if (count >= k) return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> positions = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            positions.add(sc.nextInt());
        }

        int result = signalTowers(n, k, positions);
        System.out.println(result);
    }
}
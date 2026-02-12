import java.util.*;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        sc.nextLine(); 
        
        sc.nextLine(); 
        List<String> shuffled = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            shuffled.add(sc.nextLine());
        }
        
        sc.nextLine(); 
        List<String> original = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            original.add(sc.nextLine());
        }
        
        Map<String,Integer> indexMap = new HashMap<>();
        for (int i = 0; i < original.size(); i++) {
            indexMap.put(original.get(i), i);
        }
        List<Integer> seq= new ArrayList<>();

        for (String s : shuffled) {
            seq.add(indexMap.get(s));
        }
        int longest = 1, current = 1;
        for (int i = 1; i < N; i++) {
            if (seq[i] == seq[i - 1] + 1) current++;
            else current = 1;
            longest = Math.max(longest, current);
        }

        int minOperations = N - longest;
        System.out.println(minOperations);
    }
    private static int findLIS(int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int maxLen = 1;

        for (int i=1; i< n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }

        return maxLen;
    }
}

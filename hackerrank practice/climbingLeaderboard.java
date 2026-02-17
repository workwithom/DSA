import java.util.*;
import java.util.stream.*;

class Result {

    /*
     * Complete the 'climbingLeaderboard' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY ranked
     *  2. INTEGER_ARRAY player
     */

    public static List<Integer> climbingLeaderboard(List<Integer> ranked, List<Integer> player) {
        ranked = ranked.stream().distinct().collect(Collectors.toList());
        List<Integer> result = new ArrayList<>();

        int i = ranked.size() - 1; 
        for (int score : player) {
            while (i >= 0 && score >= ranked.get(i)) {
                i--;
            }
            result.add(i + 2);
        }
        return result;
    }

}

public class climbingLeaderboard {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ranked_count = in.nextInt();
        List<Integer> ranked = new ArrayList<Integer>(ranked_count);
        for(int ranked_i=0; ranked_i < ranked_count; ranked_i++){
            int ranked_item = in.nextInt();
            ranked.add(ranked_item);
        }
        int player_count = in.nextInt();
        List<Integer> player = new ArrayList<Integer>(player_count);
        for(int player_i=0; player_i < player_count; player_i++){
            int player_item = in.nextInt();
            player.add(player_item);
        }
        List<Integer> result = Result.climbingLeaderboard(ranked, player);
        System.out.println(result);
    }
}

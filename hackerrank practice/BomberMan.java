import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'bomberMan' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. STRING_ARRAY grid
     */
    public static List<String> explode(List<String> grid ,int row , int col){
        List<StringBuilder> ans = new ArrayList<>();
        for(int i = 0 ; i < row ; i++){
            StringBuilder cell = new StringBuilder(grid.get(i));
            for(int j = 0 ; j < col ; j++){
                if(cell.charAt(j) == 'O') cell.setCharAt(j,'b');
                else cell.setCharAt(j,'O');
            }
            ans.add(cell);
        }
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(ans.get(i).charAt(j) == 'b'){
                    if(i>0){
                        if(ans.get(i-1).charAt(j) != 'b') ans.get(i-1).setCharAt(j,'.');
                    }
                    if(i<row-1){
                        if(ans.get(i+1).charAt(j) != 'b') ans.get(i+1).setCharAt(j,'.');
                    }
                    if(j>0 ){
                        if(ans.get(i).charAt(j-1) != 'b') ans.get(i).setCharAt(j-1,'.');
                    }
                    if(j<col-1){
                        if(ans.get(i).charAt(j+1) != 'b') ans.get(i).setCharAt(j+1,'.');
                    }
                    ans.get(i).setCharAt(j,'.') ;
                }
                
            }
        }
        for(int i = 0 ; i < row ; i++ ){
            grid.set(i, ans.get(i).toString());
        }
        
        return grid;
    }
    
    public static List<String> bomberMan(int n, List<String> grid) {
        int row = grid.size();
        int col = grid.get(0).length();
        
        if(n == 1) return grid;
        StringBuilder sb = new StringBuilder();
        for( int i = 0 ; i < col ; i++) sb.append('O');
        if(n%2 == 0){
            for(int i = 0 ; i < row ; i++ ){
                grid.set(i, sb.toString());
            }
            return grid;
        }
        List<String> str = explode(grid, row, col);
        if(n%4 == 3){
            return str;
        }
        return explode(str, row, col);
    }

}

public class BomberMan {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int r = Integer.parseInt(firstMultipleInput[0]);

        int c = Integer.parseInt(firstMultipleInput[1]);

        int n = Integer.parseInt(firstMultipleInput[2]);

        List<String> grid = IntStream.range(0, r).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        List<String> result = Result.bomberMan(n, grid);

        bufferedWriter.write(
            result.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}

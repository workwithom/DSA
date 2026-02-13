import java.util.*;
public class groupAnagram {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}));
    }
}
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        HashMap<Character, Integer> map = new HashMap<>(); 
        for(int i = 0; i<s.length() ;i++){
            if(map.get(s.charAt(i))==null){
                
                map.put(s.charAt(i),1);
            }else{
                map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
            } 
        }
        for(int i=0;i<t.length();i++){
            if(!map.containsKey(t.charAt(i))){
                return false;
            }
            map.put(t.charAt(i),map.get(t.charAt(i))-1);
                if(map.get(t.charAt(i))==0) map.remove(t.charAt(i));
        }
        return map.isEmpty();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        int pivot = 0;
        
        while(pivot<strs.length){
            
            if(strs[pivot]==null) {
                pivot++;
                continue; 
            }
            List<String> temp = new ArrayList<>();
            temp.add(strs[pivot]);
                for(int j = pivot + 1 ; j < strs.length ; j++ ){
                    if(strs[j]==null) continue;
                    if(isAnagram(strs[pivot],strs[j])){
                        temp.add(strs[j]);
                        strs[j]=null;
                    }
                }
                ans.add(temp);
                pivot++;
        }
        return ans;
        
    }
}
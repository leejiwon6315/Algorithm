class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] arr = s.split("");
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            cnt = (arr[i]==" ") ? 0 : cnt+1;
            answer += cnt%2== 0 ? arr[i].toLowerCase() : arr[i].toUpperCase();
        }
        
        return answer;
    }
}

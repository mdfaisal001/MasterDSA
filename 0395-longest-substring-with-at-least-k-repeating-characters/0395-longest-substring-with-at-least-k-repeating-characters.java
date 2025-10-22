class Solution {
    private int findSubstring(String s, int k){
        if (s.length() < k) return 0;
        
        int[] freq = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch-'a']++;
        }

        for(int i=0; i<s.length(); i++){
            if(freq[s.charAt(i) - 'a'] < k){
                int left = findSubstring(s.substring(0,i),k);
                int right = findSubstring(s.substring(i+1),k);
                return Math.max(left,right);
            }
        }
        return s.length();
    }
    public int longestSubstring(String s, int k) {
       return findSubstring(s,k);
    }
}
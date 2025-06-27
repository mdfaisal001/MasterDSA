class Solution {
    public int characterReplacement(String s, int k) {
        int maxLen = 0, maxFreq = 0 , l= 0 , r=0, n=s.length();
        int[] hash = new int[26];
        while(r < n){
            hash[s.charAt(r)-'A']++;
            maxFreq = Math.max(maxFreq,hash[s.charAt(r)-'A']);
            int changes = (r-l+1) - maxFreq;
            if(changes > k){
                hash[s.charAt(l)-'A']--;
                l++;
            }
            maxLen = Math.max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
}
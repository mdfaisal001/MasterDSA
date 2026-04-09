class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l=0,r=0,n=s.length();
        int maxi = 0;

        HashMap<Character,Integer> hash = new HashMap<>();
        while(r < n){
            if(hash.containsKey(s.charAt(r)) ){
                l= Math.max(l,hash.get(s.charAt(r))+1);
            }

            hash.put(s.charAt(r),r);
            maxi = Math.max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
}
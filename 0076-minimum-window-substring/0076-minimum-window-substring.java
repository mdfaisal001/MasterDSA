class Solution {
    public String minWindow(String s, String t) {
         int minLen = Integer.MAX_VALUE , start = -1;
         int l=0 , r = 0, count = 0;
         int n = s.length(), m= t.length();
         HashMap<Character,Integer> mp = new HashMap<>();
         for (int i = 0; i < t.length(); i++) {
                char c = t.charAt(i);
                mp.put(c, mp.getOrDefault(c, 0) + 1);
            }

         while(r < n){
            char ch = s.charAt(r);
            if(mp.getOrDefault(ch,0) > 0){
                count++;
            }
            mp.put(ch, mp.getOrDefault(ch,0)-1);

            while(count == m){
                if(r-l+1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                   char left = s.charAt(l);
                    mp.put(left,mp.getOrDefault(left,0)+1);
                    if(mp.getOrDefault(left,0) > 0) count--;
                    l++;
                
            }
            r++;
         }

        return (start == -1) ? "" :s.substring(start, start+minLen);
    }
}
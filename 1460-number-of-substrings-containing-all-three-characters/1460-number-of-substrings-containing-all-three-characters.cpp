class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0 , r= 0, n = s.size(),count=0, frequency = 0;
        int hash[256] = {0};
        while(r < n){
            if(hash[s[r]] == 0) frequency++;
            hash[s[r]]++;
            while(frequency  == 3){
                count += (n - r);
                hash[s[l]]--;
                if(hash[s[l]] == 0) frequency--;
                l++;
            }
            r++;
        }
        return count;
    }
};
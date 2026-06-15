class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mp;
        int l =0, r=0,n=s.size();
        int maxi = 0;
        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l,mp[s[r]]+1);
            }

            mp[s[r]] = r;
            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),maxLength = INT_MIN,count=0;
        if(s.empty()) return 1;
        for(int i=0; i<s.size(); i++){
            unordered_map<char,int>mp;
            for(int j=i; j<s.size(); j++){
                 if(mp.find(s[j]) == mp.end()){
                    mp[s[j]] = 1;
                 }
                 else{
                    maxLength = max(maxLength,j-i);
                    break;
                 }
                
            }
        }
        return maxLength;
    }
};*/
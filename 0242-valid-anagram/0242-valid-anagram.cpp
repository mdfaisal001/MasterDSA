class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto it : t){
            mp[it]--;
        }
       for(auto pair : mp){
            if(pair.second != 0) return false;
       }
       return true;
    }
};
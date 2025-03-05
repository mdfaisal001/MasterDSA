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

/* by skipping above two loops just for loop through n because the
        length will be equeal then increase and decrease freq in single loop before this length not equeal
        return false
           if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }*/
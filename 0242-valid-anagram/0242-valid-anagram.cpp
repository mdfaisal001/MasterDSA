class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
         unordered_map<char,int> mp;
         for(auto ch : s){
             mp[ch]++;
         }

         for(auto it : t){
             if(mp.find(it) == mp.end()) return false;

             mp[it]--;
             if(mp[it] == 0) mp.erase(it);
         }
        return mp.empty();
        
       }
       
    
};

/*class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        if (s.length() != t.length())
            return false;
       for(char letters : t){
           freq[letters - 'a']++;
       } 
       for(auto character : s){
           freq[character - 'a']--;
           if(freq[character-'a'] < 0) return false;
        }
        return true;
       }
       
    
};*/
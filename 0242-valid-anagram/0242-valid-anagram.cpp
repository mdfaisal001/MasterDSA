class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if (s.length() != t.length())
            return false;
       for(char letters : t){
           mp[letters]++;
       } 
       for(auto character : s){
            if(mp.find(character) != mp.end()){
                mp[character]--;
                if(mp[character] == 0) mp.erase(character);
            }
       }
       return mp.empty();
    }
};
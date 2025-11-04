class Solution {
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
       
    
};
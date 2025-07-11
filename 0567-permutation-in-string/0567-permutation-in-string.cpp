class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
         if(s1.length() > s2.length()) return false;
        for(auto letters:s1){
            hash1[letters-'a']++;
        }
        for(int i=0; i<s1.size(); i++){
                hash2[s2[i]-'a']++;
        } 
        
        if(hash1== hash2) return true;
        for(int i=s1.size(); i<s2.size(); i++){
            hash2[s2[i]-'a']++;
            hash2[s2[i-s1.size()]-'a']--;
            if(hash1 == hash2) return true;
        }
        return false;
        /*s1->fixed size window , indirect one for anagram we need equal size */
    }
};
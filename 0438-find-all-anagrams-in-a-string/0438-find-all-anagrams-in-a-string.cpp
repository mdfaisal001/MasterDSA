class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        int hashP[26] = {0};
        for(auto it : p){
            hashP[it - 'a']++;
        }
        for(int i=0; i<s.size(); i++){
            int hash[26] = {0};
            int count = 0;
            for(int j = i ; j<s.size(); j++){
                hash[s[j] - 'a']++;
                bool isAnagram = true;
                for(int k = 0 ; k< 26 ; k++){
                    if(hashP[k] != hash[k]){
                        isAnagram = false;
                        break;
                    }
                }
                if(isAnagram) result.push_back(i);
            }
        }
        return result;
    }
};



/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        for(int i=0; i<s.size(); i++){
            int hash[256] = {0};
            int count = 0;
            for(int j = i ; j<s.size(); j++){
                if(p.find(s[j]) != string::npos && hash[s[j]] == 0){
                    count++;
                    hash[s[j]] = 1;
                }
                else break;
                if(count == p.size()){
                    result.push_back(i);
                    break;
                }
                
            }
        }
        return result;
    }
};*/
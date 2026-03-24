class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        string key = s.substr(0,10);
        mp[key]++;
        vector<string>result;
        for(int i=10;i<s.size();i++){
            
            key.erase(0,1);
            key.push_back(s[i]);
            mp[key]++;

            if(mp[key] == 2){
                result.push_back(key);
            }
        }

        return result;
    }
};
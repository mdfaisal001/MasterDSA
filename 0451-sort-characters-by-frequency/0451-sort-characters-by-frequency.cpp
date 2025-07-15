class Solution {
public:
    string frequencySort(string s) {
        // first i will count the frequency ;
        // based on the frequency i will push the char in to bucket 
        // will make a string from last to first thus give decreasing order;
        unordered_map<char,int>mp;
        int n = s.size(); //length;
        for(int i = 0; i<n; i++){
            mp[s[i]]++; // counting the frequency through hash map;
        }

        // push them in to the buckets;
        vector<vector<char>> bucket(n+1); // implementing the bucket;
        for(auto pair : mp){
            bucket[pair.second].push_back(pair.first);
            // pair.second represents the frequency and first rep char;
        };
        //output string;
        string result = "";
        for(int i = n ; i>=0; i--){
            for(char letters:bucket[i]){
                result+=string(i,letters); // forming the string based on the frequency;
            }
        }
        //return the reconstructed string;
        return result;
    }
};
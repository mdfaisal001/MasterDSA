class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> freq;
        int hash[256] = {0};
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        vector<int>result;
        int l=0,r=0,n=s.size();
        int count = 0;
        while(r < n){
            if(hash[s[r]] == 0) count++;
            hash[s[r]] = 1;
            if(freq.find(s[r]) != freq.end()){
                freq[s[r]]--;
                if(freq[s[r]] == 0) count--;
                if(count==0){
                    result.push_back(r-l+1);
                    l = r+1;
                }
                r++;
            }
        }
        return result;
    }
};
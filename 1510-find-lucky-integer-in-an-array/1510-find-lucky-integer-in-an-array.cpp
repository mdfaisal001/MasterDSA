class Solution {
public:
    int findLucky(vector<int>& arr) {
        // use hash array instead of map to minimize tht tc;
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        int lucky = -1;
        for(auto freq : mp){
            if(freq.second == freq.first && freq.second > lucky) lucky = freq.first; 
            
        }
        return lucky;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0] = -1;
        int n = nums.size(), sum = 0;int mod = -1;
        for(int i=0; i<n ; i++){
            sum+=nums[i];
            mod = (k==0)? sum : sum%k; 
            if(hash.find(mod) != hash.end()){
                int len = i - hash[mod];
                if(len >=2) return true;
            }
            if(hash.find(mod) == hash.end()) {
                    hash[mod] = i;
            }

        }
        return false;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int>result;
        for(int i = 0; i<n; i++){
            int remainder = target - nums[i];
            if(mp.find(remainder) != mp.end()){
                result.push_back(mp[remainder]);
                result.push_back(i);
            }
            else mp[nums[i]] = i;
            
        }
        return result;
    }
};
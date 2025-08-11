class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0,r=0,n =  nums.size();
        unordered_map<int,int>mp;
        long long maxi = 0,sum = 0;

        while(r < n){
                mp[nums[r]]++;
                sum+=nums[r];
        
            while(mp.size() > k || mp[nums[r]] >1){
                mp[nums[l]]--;
                sum-=nums[l];
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            if(mp.size() == k){
                maxi = max(maxi,sum);
            }
            r++;
        }
        return maxi;
    }
};
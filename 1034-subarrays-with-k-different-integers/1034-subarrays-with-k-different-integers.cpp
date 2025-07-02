class Solution {
private:
    int subarrayLessThanEqualToK(vector<int> &nums, int goal){
        int l = 0 , r = 0, n = nums.size(),subarrayCount = 0,count = 0;
        unordered_map<int,int>mp ;
        while(r < n){
            if (goal <0) return 0;
            if(mp[nums[r]] == 0) count++;
            mp[nums[r]]++;
            while(count > goal){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) count--;
                l++;
            }
            subarrayCount += (r - l + 1);
            r++;
        }
        return subarrayCount;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayLessThanEqualToK(nums,k) - subarrayLessThanEqualToK(nums,k-1);
    }
};

/*int  n = nums.size() ,subArray = 0;
        for(int i=0; i<n ;i++){
            unordered_map<int,int> hash;
            int count = 0;
            for(int j = i; j<n ; j++){
                if(hash[nums[j]] == 0) count++;
                hash[nums[j]]++;
                
                if(count == k){
                    subArray++;
                }
            }
        }
        return subArray;*/
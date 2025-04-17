class Solution {
private:
    void permutation(int index, vector<int> nums, vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int> mp;
        for(int i=index ; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()) continue;
            mp.insert(nums[i]);
            swap(nums[index],nums[i]);
            permutation(index +1 , nums, result);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        permutation(0,nums,result);
        return result;
    }
};
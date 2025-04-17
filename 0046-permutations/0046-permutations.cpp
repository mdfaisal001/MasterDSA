class Solution {
private:
    void findPermutation(int index, vector<int> nums, vector<vector<int>> &result){
        if(index == nums.size() -1) {
            result.push_back(nums);
            return;
        } // base case
        for(int i = index ; i< nums.size() ; i++){
            swap(nums[index],nums[i]);
            findPermutation(index+1 , nums,result);    // we are giving index +1 not i + 1 so the call goes level by level
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    findPermutation(0,nums,result);
    return result;   
    }
};
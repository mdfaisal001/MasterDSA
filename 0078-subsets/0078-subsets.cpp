class Solution {
private:
    void findSubset(int index , vector<vector<int>> &result,vector<int> &temp, vector<int> &nums){
        int n = nums.size();
        if(index == n){
            result.push_back(temp);
            return;
        } // base case for printing the subset;

        temp.push_back(nums[index]);
        findSubset(index+1,result,temp,nums);
        temp.pop_back();
        findSubset(index+1, result,temp,nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        findSubset(0,result,temp,nums);
        return result;
    }
};
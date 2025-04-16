class Solution {
private:
void permutation(vector<int> &nums,vector<vector<int>> &result,int index){
    if(index == nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i = index; i<nums.size();i++){
        swap(nums[index],nums[i]);
        permutation(nums,result,index+1);
        swap(nums[index],nums[i]);
    }
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        permutation(nums,result,0);
        return result;

        
    }
};
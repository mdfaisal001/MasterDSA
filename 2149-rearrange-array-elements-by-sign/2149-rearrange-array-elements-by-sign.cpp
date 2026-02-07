class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        int pve = 0;
        int neg  = 1;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] < 0){
                result[neg] = nums[i];
                neg+=2;
            }
            else{
                result[pve] = nums[i];
                pve+=2;
            }
        }

        return result;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int pos =0, neg = 1;
       int n = nums.size();
       vector<int> result(n,0);

       for(int i=0;i<nums.size(); i++){
            if(nums[i] >=0){
                result[pos] = nums[i];
                pos+=2;
            }
            else{
                result[neg]=nums[i];
                neg+=2;
            }
       }

       return result;
    }
};
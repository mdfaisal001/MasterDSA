class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bucket1 = 0;
        int bucket2 = 0;
        long Xor = 0;
        for(auto it : nums){
            Xor = Xor ^ it;
        }
        int rightMost = (Xor & (Xor - 1)) ^ Xor;

        for(auto it : nums){
            if(it & rightMost){
                bucket1 = bucket1 ^ it;
            }
            else{
                bucket2 = bucket2 ^ it;
            }
        }
        return {bucket1 , bucket2};
    }
};
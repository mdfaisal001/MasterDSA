class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++){
            int bitCount = 0;
            for(auto it : nums){
                if(it & (1 << i)) bitCount++;
            }
            if(bitCount % 3 != 0){
                result = result | (1 << i);
            }
        }
        return result;
    }
};
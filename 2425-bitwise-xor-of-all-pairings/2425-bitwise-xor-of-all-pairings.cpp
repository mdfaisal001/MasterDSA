class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int xor1 = 0;
        int xor2 = 0;
        for(auto val : nums1){
           xor1^=val;
        }
        for(auto val2 : nums2){
            xor2^=val2;
        }
        if(nums2.size()%2!=0){
            res^=xor1;
        }
        if(nums1.size()%2!=0){
            res^=xor2;
        }
        return res;
    }
};
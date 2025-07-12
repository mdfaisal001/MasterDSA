class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1,suffix=1, maxProduct = 0;
        int n=nums.size();
        if(n<2) return nums[0];
         for(int i=0;i<n;i++){
            prefix*=nums[i];
            maxProduct = max(maxProduct,prefix);
            if(prefix ==0) prefix = 1;
         }
         for(int j = n-1; j>=0; j--){
            suffix*=nums[j];
            maxProduct = max(maxProduct,suffix);
            if(suffix ==0) suffix = 1;
         }

        return maxProduct;
    }
};

/*class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1, maxProduct = 0;
        if(nums.size() < 2) return nums[0];
        product*= nums[0];
        if(product == 0) product = 1;
        for(int i=1; i<nums.size()-1; i++){
            product *= nums[i];
            maxProduct = max(product,maxProduct);
            if(product ==0) product = 1;
            if((product < 0) && (nums[i +1] > 0)) product =1;
        }
        product*=nums[nums.size()-1];
        maxProduct = max(product,maxProduct);
        return maxProduct;
    }
};*/
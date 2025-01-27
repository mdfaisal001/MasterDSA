class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        int n = nums.size();
        
        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) one++;
            else if (nums[i] == 2) two++;
        }
        
        // Assign 0s, 1s, and 2s back to the array
        int j = 0;
        for (int i = 0; i < zero; i++) nums[j++] = 0;
        for (int i = 0; i < one; i++) nums[j++] = 1;
        for (int i = 0; i < two; i++) nums[j++] = 2;
    }
};
/*public:
    void sortColors(vector<int>& nums) {
       int low = 0;
       int mid =0;
       int high = nums.size()-1;
       while(mid <= high){
         if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
         }
         else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
         }
         else{
            mid++;
         }
       }
     
    }*/

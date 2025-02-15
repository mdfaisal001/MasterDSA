class Solution {
private:
    int binarySearch(int low, int high , vector<int> &nums){
        int mid = low + (high - low)/2; // to avoid overflow
        //basecase
        if( low == high ) return nums[low];
        if(nums[mid] > nums[high]){
            return binarySearch(mid+1,high,nums);
        }
        else{
            return binarySearch(low,mid,nums);
        }
    }
public:
    int findMin(vector<int>& nums) {
      int low = 0; 
      int high = nums.size()-1;
      return binarySearch(low,high,nums);
    }
};

/*   vector<int>temp;
       for(int i=1;i<nums.size(); i++){
            if(nums[i]<nums[i-1]) {
                temp.push_back(nums[i]);
            }
       }
       if(temp.size()==0) return nums[0];
       int mini = INT_MAX;
       for(int i=0; i<temp.size(); i++){
                mini = min(temp[i],mini);
       }
       return mini;
       
       
       //iterative 
       int low = 0;
      int high = nums.size()-1;
      while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid]> nums[high]){
            low = mid+1;
        }
        else{
            high = mid;
        }
      }
      return nums[low];
       */
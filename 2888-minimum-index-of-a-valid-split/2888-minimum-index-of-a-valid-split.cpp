class Solution {
public:
    int minimumIndex(vector<int>& nums) {
    // 1.finding the dominant elem using morre's algo; or with hash and bucket;
    //2. finding the point which having more dominant elem and count it
    //3. for dominant elem it should 2x of dominant elem > length;
      int n = nums.size();
      int majorityElem = 0;
      int count = 0;
      for(int i=0; i<n; i++){
         if(count ==0){
            majorityElem = nums[i];
            count = 1;
         }
         else if(nums[i] == majorityElem){
            count++;
         }
         else count--;
      } // found the majority or dominant elem;

      // lets check for the subarrays which having the dominant elem;
      int dominantCount = 0;
      for(auto num : nums){
          if(num == majorityElem) dominantCount++;
      }
       
       //
      int leftFreq = 0;
      for(int i=0; i<n;i++){
         
         if(nums[i]==majorityElem) leftFreq++;
         int leftSize = i+1;
         int rightSize = n - leftSize;
         int rightFreq = dominantCount - leftFreq;
         if(2 * leftFreq > leftSize && 2*rightFreq > rightSize ){
              return i;
         }
      }

    return -1;

 }
};
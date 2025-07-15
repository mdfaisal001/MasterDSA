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
       
       /* the problem was about the divided subarrays should have tht dominant majority elem as dominant , 
       1.so for left side comparison finding the left size which is i+1,
       2. for frequency = which is counting the dominant elem;
       3. right side = n -leftside;
       4. right freq = dominantfre - left freq
       whenever both condition true we return the indexes because we are going from r to l so its always minimum ;
       */
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
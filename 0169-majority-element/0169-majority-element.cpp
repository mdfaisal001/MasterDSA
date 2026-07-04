class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 1, majElem  = nums[0],n = nums.size();

      for(int i=1;i<n; i++){
         if(count ==0){
            majElem = nums[i];
            count = 1;
         }
         else if(nums[i] == majElem) count++;
         else count--;
      }

      unordered_map<int,int>  mp;
      for(auto num : nums){
         mp[num]++;
      }

      if(mp[majElem] > n/2 ) return majElem;

      return -1;
    }
};


/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>hash;
       int size = nums.size() /2;
       //1.counting the frequency;
       for(auto num : nums){
            hash[num]++;
       } 
       // searching for the majority elem
       int majorityElem;
       for(auto pair: hash){
            if(pair.second > size){
                majorityElem = pair.first;
                break;
            }
       }
       return majorityElem;
    }
};*/
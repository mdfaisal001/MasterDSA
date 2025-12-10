class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 1 , n = nums.size();
       int majElem = nums[0];

       for(int i=1; i<nums.size(); i++){
           if(count ==0){
              count = 1;
              majElem = nums[i];
           }
           else if(nums[i] != majElem) count--;
           else count++;
       }

       int freq = 0;
       for(int i=0; i<nums.size(); i++){
            if(nums[i] == majElem) freq++;
       }
       if(freq >= n/2) return majElem;
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
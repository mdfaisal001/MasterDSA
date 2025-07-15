class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count =1;
       int elem = nums[0];
       for(int i=1;i<nums.size(); i++){
            if(count == 0){
                elem = nums[i];
                count = 1;
            }
            else if(nums[i] == elem ){
                count++;
            }
            else{
                count--;
            }
       }  // boyer morres algo , the maximum elements frew is not cancelled by othe el
       
       //2.checking that its really more than n/2;
       int freq = 0;
       for(int i=0; i<nums.size(); i++){
            if(nums[i] == elem) freq++;
       }
       if(freq > nums.size()/2) return elem;
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
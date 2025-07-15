class Solution {
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
};
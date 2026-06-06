class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int elem1 = 0, elem2 = 0;
       int freq1 = 0, freq2= 0;
       int n = nums.size();

       for(int i=0; i<n; i++){

            if(nums[i] == elem1 ) freq1++;
            else if(nums[i] == elem2) freq2++;
            else if(freq1 == 0){
                freq1=1;
                elem1 = nums[i];
            }
            else if(freq2 == 0){
                freq2 = 1;
                elem2 = nums[i];
            }
            else {
                freq1--;
                freq2--;
            }

       }

       // checking the frequency of maj elem greater than the n/3

       int currFreq1 = 0, currFreq2 = 0;

       for(int i=0;i<nums.size(); i++){
           if(nums[i] == elem1) currFreq1++;
           else if(nums[i] == elem2) currFreq2++; 
       }
    
      //For result 
      vector<int>result;
       if(currFreq1 > n/3) result.push_back(elem1);
       if (currFreq2 > n/3) result.push_back(elem2); 
       return result;
    }

    
};
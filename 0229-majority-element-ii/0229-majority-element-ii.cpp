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

       } /*Quick note for me :how it asures the values is always <=2?
         because when n is divided by 3 only 2 elements is possible to occur morethan n/3 , 9 /3 = 3, if 3 elem occur more than n/3, the freq is 12,its greater than the n */

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
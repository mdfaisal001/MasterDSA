class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1  =0 ,elem2 = -1;
        int dominantElem1 = 0, dominantElem2 = 0; 
        int n = nums.size();
        //1.traccking the two dom elem;

        // bo
        for(int i= 0; i<n; i++){
            if(nums[i] ==elem1) dominantElem1++;
            else if(nums[i] == elem2) dominantElem2++;
            else if(dominantElem1 == 0){
                dominantElem1 = 1;
                elem1 = nums[i];
            }
            else if(dominantElem2 == 0){
                dominantElem2 = 1;
                elem2=nums[i];
            }
           
            else {
                dominantElem1--;
                dominantElem2--;
            }
        }
        // validate its n/3;
        int countOfDOM1  = 0, countOfDOM2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]== elem1) countOfDOM1++;
            else if(nums[i] == elem2) countOfDOM2++;
        }

        // final validation ;
        vector<int>result;
        if(countOfDOM1 > n/3){
            result.push_back(elem1);
        }
        if(countOfDOM2 > n/3){
            result.push_back(elem2);
        }
     return result;
    }
};
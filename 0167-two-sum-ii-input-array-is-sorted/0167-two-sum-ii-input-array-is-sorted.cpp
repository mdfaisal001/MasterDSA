class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0, high = n-1;
        vector<int>result;
        while(low <= high){
            int sum = numbers[low]+numbers[high];
             if(sum == target){
                result.push_back(low+1);
                result.push_back(high+1);
                break;
            }
            if(sum > target){
                high--;
            }
            else{
                low++;
            }
           
        }
        return result;
    }
};
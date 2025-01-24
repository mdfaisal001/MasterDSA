class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>> temp;
       for(int i=0; i<nums.size(); i++){
           temp.push(nums[i]);
       }
       for(int i= 0;i<k-1; i++){
          temp.pop();
       }
       return temp.top();
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int farthest = 0;
        int current = 0;
        int jump = 0;
        if(nums.size()<2) return 0;
        for(int i=0; i<nums.size()-1; i++){
           farthest = max(farthest , i+nums[i]);
           if(i==current){
              jump++;
              current = farthest;
           }
        }
        return jump;
    }
};

/*class Solution {
public:
    int jump(vector<int>& nums) {
        
        int farthest = 0;
        int count = 0;
        if(nums.size()<2) return 0;
        for(int i=0; i<nums.size(); i++){
            if(i + nums[i] > farthest) count++;
            farthest = max(farthest , i+nums[i]);
            if(farthest >= nums.size()-1 ) return count;
        }
        return 0;
    }
};*/
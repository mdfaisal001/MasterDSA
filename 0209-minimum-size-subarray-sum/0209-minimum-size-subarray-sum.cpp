class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l=0,r=0,n=nums.size();

        int sum=0;
        int mini = INT_MAX;
       while(r < n){
            sum+=nums[r];

            while(sum >= target){
                mini = min(mini,r-l+1);
                sum-=nums[l];
                l++;
            }

            r++;
       }

       return (mini == INT_MAX) ? 0: mini;
    }
};

/*for(int i=0; i<n; i++){
            int sum = 0;
            for(int j =i; j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    minLength = min(minLength , j-i+1);
                }
            }
        }
        return (minLength != INT_MAX)? minLength:0;*/
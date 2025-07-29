class Solution {
private:
    int countSubarrays(vector<int>&nums,int goal){
        int n = nums.size(), l=0,r=0,odd=0,subarray = 0;
        while(r < n){
            if(nums[r]&1) odd++;
            while(odd > goal){
                if(nums[l]&1) odd--;
                l++;
            }
            subarray+=(r-l+1);
            r++;
        }
        return subarray;

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size(), l=0,r=0,total=0;
       return countSubarrays(nums,k) - countSubarrays(nums,k-1);
    }
};

/*int total = 0 , n = nums.size();
        for(int i=0; i<n ;i++){
            int count =0;
            for(int j= i ; j<n; j++){
                if(nums[j]&1) count++;
                if(count==k){
                    total++;  
                }
            }
        }
        return total;*/
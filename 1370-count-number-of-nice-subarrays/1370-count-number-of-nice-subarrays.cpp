class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size(),total = 0,prefixSum = 0;
       unordered_map<int,int> freq;
       freq[0] =1;
       for(int i=0; i<n ;i++){
            nums[i] = (nums[i]&1)?1:0;
            prefixSum+=nums[i];
            int leftInterval = prefixSum - k;
            if(freq.find(leftInterval) != freq.end()){
                total+=(freq[leftInterval]);
            }
            freq[prefixSum]++;
       }
       return total;
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
        return total;
        
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
        
        
        */
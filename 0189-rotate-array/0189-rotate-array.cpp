class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> temp(n);
       k %= n;
      for(int i = 0; i<n; i++){
         temp[(k + i) %n] = nums[i];
      }
     
      
      nums = temp;
    }
};

/*  int n= nums.size();
        vector<int> temp(n);
        for(int i=0; i<k;i++){
            for(int j=1; j<n;j++){
                temp[j]= nums[j-1];
            }
            temp[0]=nums[n-1];
            nums = temp;
        }*/
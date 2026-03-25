class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n1 = *min_element(nums.begin(),nums.end());
        int n2 = *max_element(nums.begin(),nums.end());
        int gcd = 1;
        for(int i=1; i<= min(n1,n2); i++){
            if(n1%i==0  &&  n2%i==0){
                gcd = i;
            }
        }

        return gcd;
    }
};
class Solution {
private:
    int findMax(vector<int> piles){
        int ans = INT_MIN;
        int n  = piles.size();
        for(int i=0 ; i<n; i++){
            ans = max(ans,piles[i]);
        }
        return ans;
    }
    long long total(vector<int>& piles, int hours){
        int n= piles.size();
        long long total = 0;
        for(int i=0; i<n; i++){
            total += ceil( (double)piles[i] / (double) hours);
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int low = 1;
        int high = findMax(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long val = total(piles,mid);
            if(val <= h){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
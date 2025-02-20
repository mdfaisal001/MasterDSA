class Solution {
private:
    int minimum(vector<int>bloomDay){
        int mini = INT_MAX;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
             mini = min(mini,bloomDay[i]);
        }
        return mini;
    }
     int maximum(vector<int>bloomDay){
        int maxi = INT_MIN;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
             maxi = max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    bool possible(vector<int>&bloomDay, int m , int k, int day){
        int n = bloomDay.size();
        int count = 0 ; int maxCount = 0;
        for(int i=0;i<n; i++){
            if(bloomDay[i]<=day){
                count++; // if the blooming day is less than or equal its possible so inc the counter
            }
            else{
                maxCount += (count/k); // getting how many exact k pairs from the count;
                count = 0;
            }
        }
        maxCount+=(count/k);
        if(maxCount >= m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //edge case
        int n = bloomDay.size();
        long long size = m * 1LL * k* 1LL;
        if(n < size) return -1;
        int low = minimum(bloomDay);
        int high = maximum(bloomDay);
        while(low <= high){
            int mid = low + (high - low) / 2;
            bool val = possible(bloomDay,m,k,mid);
            if(val == true){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
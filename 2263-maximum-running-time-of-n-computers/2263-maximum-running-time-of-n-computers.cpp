class Solution {
private:
    bool canPossible(long long time , int n , vector<int> &batteries){
        long long total = 0;
        for(int i=0;i<batteries.size(); i++){
            total+=min((long long) batteries[i] , time);
        }
        return total >= time * n;  // checking greeding , the total time required for the n comp with this time is t *n , checking the min time by each battery to check its more than total time.
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = accumulate(batteries.begin(),batteries.end(),0LL);
        while(low <= high){
            long long mid = low + (high -low)/2;
            if(canPossible(mid,n,batteries)){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
    }
};
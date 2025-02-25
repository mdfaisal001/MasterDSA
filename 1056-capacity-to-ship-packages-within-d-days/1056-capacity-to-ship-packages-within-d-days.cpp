class Solution {
private:
    int findMin(vector<int> & weights, int weight){
        int minDays = 1;
        int minWeight = 0;
        for(int i=0; i<weights.size(); i++){
            if(minWeight + weights[i] <= weight){
                minWeight += weights[i];
            }
            else{
                minDays++;
                minWeight = weights[i];
            }
        }
        return minDays;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int val = findMin(weights,mid);
            if(val <= days){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
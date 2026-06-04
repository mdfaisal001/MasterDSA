class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end()); // just arranging all the intervals to come closer to its range 
        for(int i=0; i<n;i++){
            if(result.empty() || result.back()[1] < intervals[i][0]){ // if the result is empty of the previous range is less than the new range mean we directly push the subinterval
                result.push_back(intervals[i]);
            }
            else{ // else extend our current interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd = 0, even = 0, minCost = 0;
        // the intuition is the same odd or eve pos to pos cost 0 else cost 1;
        for(int i = 0; i<n ; i++){
            if(position[i]&1) odd++;
            else even++;
        }
        minCost = min(odd,even);
        return minCost;
    }
};
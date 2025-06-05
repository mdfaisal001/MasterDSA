class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, mini = INT_MAX;
       for(int i=0; i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxProfit = max(maxProfit , prices[i]-mini);
       }
       return maxProfit; 
    }
};


/* class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
       for(int i=0; i<prices.size()-1;i++){
            for(int j=i+1; j<prices.size(); j++){
                int profit = 0;
                 if(prices[i] < prices[j]){
                     profit = prices[j] - prices[i];
                 }
                 maxProfit = max(maxProfit,profit);
            }
       }
       return maxProfit; 
    }
};*/
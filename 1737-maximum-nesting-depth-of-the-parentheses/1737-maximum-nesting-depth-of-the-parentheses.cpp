class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count =0;
        for(char paranthesis : s){
            if( paranthesis == '('){
                count++;
            }
            else if(paranthesis == ')'){ 
                count--;
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};
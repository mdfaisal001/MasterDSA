class Solution {
public:
    int romanToInt(string s) {
    map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
       int num = 0;
       int n = s.size();
      
       for(int i=0;i<n; i++){
            if(i < n-1 && mp[s[i]]  < mp[s[i+1]]){
                num = num - mp[s[i]];
            }
            else{
                num = num + mp[s[i]];
            }
       } 
       return num;
    }
};
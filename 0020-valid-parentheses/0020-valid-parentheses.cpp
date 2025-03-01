class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true; // Handle empty string case
        
        stack<char> st;
       unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
       
        
        for(int i =0; i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                st.push(s[i]);
            }
            else{
                if(st.empty() || st.top()!=mp[s[i]]){
                    return false;
                }
                st.pop();
            }
            
        }
        return st.empty();
    }
};

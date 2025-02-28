class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true; // Handle empty string case
        
        string st;
        map<char,char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                // If it's an opening bracket, push it onto the stack
                st.push_back(s[i]);
            } else {
                // If it's a closing bracket, check if it matches the top of the stack
                if (st.empty() || mp[st.back()] != s[i]) {
                    return false; // Invalid if stack is empty or brackets don't match
                }
                st.pop_back();
            }
        }
        return st.empty(); // True if stack is empty at the end
    }
};

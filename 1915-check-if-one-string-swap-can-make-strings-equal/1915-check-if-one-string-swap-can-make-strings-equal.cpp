class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        
        vector<int> diff;
        
        // Find the positions where the strings differ
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        // If there are exactly 2 differences, check if swapping can fix it
        if (diff.size() == 2) {
            int i = diff[0], j = diff[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }
        
        // If no differences or more than 2 differences, return false
        return diff.empty();
    }
};

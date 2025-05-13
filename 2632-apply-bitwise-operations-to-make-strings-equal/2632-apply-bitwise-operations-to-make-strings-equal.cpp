class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if((s.find('1') != string::npos) == (target.find('1') != string::npos)) return true;
        return false;
    }
};
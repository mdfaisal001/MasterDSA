class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> freq1(256, 0), freq2(256, 0);

        for (char c : s1) freq1[c]++;
        for (int i = 0; i < s1.length(); i++) freq2[s2[i]]++;

        if (freq1 == freq2) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            freq2[s2[i]]++;                          // add right
            freq2[s2[i - s1.length()]]--;            // remove left

            if (freq1 == freq2) return true;
        }

        return false;
    }
};

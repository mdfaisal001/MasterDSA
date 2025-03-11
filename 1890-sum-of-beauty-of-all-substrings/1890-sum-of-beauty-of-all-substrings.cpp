class Solution {
private:
    void frequency(map<char, int> &mp, const string &substring) {
        for (char c : substring) {
            mp[c]++;
        }
    }

public:
    int beautySum(string s) {
        int sum = 0;

        // Generate all substrings and calculate beauty
        for (int i = 0; i < s.size(); i++) {
            map<char, int> mp; // Fresh map for each starting index

            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++; // Update frequency map dynamically

                // Find min and max frequency elements in the map
                auto minimum = min_element(mp.begin(), mp.end(), 
                    [](const auto &a, const auto &b) { return a.second < b.second; });
                auto maximum = max_element(mp.begin(), mp.end(), 
                    [](const auto &a, const auto &b) { return a.second < b.second; });

                // Calculate beauty difference
                int maxi = maximum->second;
                int mini = minimum->second;
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;  // Count character frequencies
        
        return backtrack(freq);
    }

private:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, val] : freq) {
            if (val > 0) {
                count++;  // Count current sequence
                freq[ch]--;  // Use this character
                count += backtrack(freq);  // Generate further sequences
                freq[ch]++;  // Backtrack to restore character count
            }
        }
        return count;
    }
};

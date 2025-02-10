class Solution {
public:
    string clearDigits(string s) {
        for (int i = 0; i < s.size(); ) {  // No increment here, since `erase` modifies the string
            if (isdigit(s[i])) {  // Check if the current character is a digit
                if (i > 0) {  // Ensure there's a left character to remove
                    s.erase(i - 1, 2);  // Remove the left character and the digit
                    i = 0;  // Reset the loop to start from the beginning
                } else {
                    s.erase(i, 1);  // If there's no left character, remove only the digit
                }
            } else {
                i++;  // Increment if no erasure is performed
            }
        }
        return s;
    }
};

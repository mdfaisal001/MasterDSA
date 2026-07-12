class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string first = strs[0];
        string last = strs[strs.size()-1];

        int n = min(first.size(),last.size());
        string result = "";
        if(first[0] != last[0]) return "";
        for(int i=0;i<n;i++){
            if(first[i] != last[i]){
                break;
            }
            result+=first[i];
        }

        return result;

    }
};

// !=0 edge case;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int n = g.size() , m = s.size();
        int ptr1 = 0 , ptr2 = 0;
        while(ptr1 < n && ptr2 < m){
             if(s[ptr2] >= g[ptr1]){
                count++;
                ptr1++;
             }
             
             ptr2++;
        }
        return count;
    }
};
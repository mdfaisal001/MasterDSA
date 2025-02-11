class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int n2 = part.size();
        for(int i=0 ; i<n; i++){
             size_t  pos = s.find(part);
             if(pos!=string::npos){
                s.erase(pos,n2);
             }
        }
        return s;
    }
};
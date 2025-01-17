class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        int sum=0;
        for(int i=0; i<derived.size(); i++){
           res^=derived[i];
        }
        if(res%2==0) return true;
        return false;
    }
};
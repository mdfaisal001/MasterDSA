class Solution {
private:
    // Check if a string has all unique characters
    bool isUnique(const string& s) {
        unordered_set<char> st;
        for (char ch : s) {
            if (st.count(ch)) return false;
            st.insert(ch);
        }
        return true;
    }

    // Check if current string can be added to existing
    bool canMerge(const string& a, const string& b) {
        unordered_set<char> st(a.begin(), a.end());
        for (char ch : b) {
            if (st.count(ch)) return false;
        }
        return true;
    }

    void solve(vector<string>& arr, int index, string curr, int& maxi) {
        if (index == arr.size()) {
            if (isUnique(curr)) {
                maxi = max(maxi, (int)curr.size());
            }
            return;
        }

        // \U0001f449 Don't pick current string
        solve(arr, index + 1, curr, maxi);

        // \U0001f449 Pick current string if no conflict
        if (canMerge(curr, arr[index])) {
            solve(arr, index + 1, curr + arr[index], maxi);
        }
    }

public:
    int maxLength(vector<string>& arr) {
        int maxi = 0;
        solve(arr, 0, "", maxi);
        return maxi;
    }
};


/*class Solution {
private:
    bool isUnique(string str,string str2){
        if(str2.size() == 0) return true;
         for(auto ch :str){
            if(str2.find(ch) != string::npos){
                return false;
            }
         }
         return true;
    }
    void findLength(int index,string subsequence, vector<string> &arr , int size,int &maxi){
        
        if(index == arr.size()){
            maxi = max(maxi,size);   
            return;   
        }
        for(int i=index; i<arr.size(); i++){
            if(isUnique(arr[i],subsequence)){
                string temp = subsequence;
                subsequence+=arr[i];
                
                findLength(i+1,subsequence,arr,subsequence.size(),maxi);
                subsequence = temp;
            }
        }
}

public:
    int maxLength(vector<string>& arr) {
        string  subsequence= "";
        int maxi = 0;
        findLength(0,subsequence,arr,0,maxi);
        return maxi;
    }
};*/
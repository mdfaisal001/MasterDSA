class Solution {
private:

    // ✅ Check if a single word has all unique characters (no duplicates within itself)
    bool isUnique(string worditself){
        unordered_set<char> st;
        for(auto ch : worditself){
            if(st.count(ch)) return false; // if already present → not unique
            st.insert(ch);                 // else insert
        }
        return true; // if no duplicates, return true
    }

    // ✅ Check if 'searchString' can be added to 'defalt' without any overlapping characters
    bool findUnique(string searchString , string defalt){
        unordered_set<char> set(defalt.begin(), defalt.end()); // create set from existing characters
        for(auto ch : searchString){
            if(set.count(ch)) return false; // if any char is already in set → can't add
        }
        return true; // all characters are unique
    }

    // ✅ Recursive function to try every combination (pick / not pick)
    void findMax(int index, vector<string>& arr, string temp, int &maxi){
        
        // \U0001f501 Base Case: If we've checked all strings
        if(index == arr.size()){
            if(isUnique(temp)) {  // only consider if temp itself is valid
                maxi = max(maxi, (int)temp.size()); // update the max size
            }
            return;
        }

        // \U0001f501 Choice 1: Pick current string if it's valid with temp
        if(findUnique(arr[index], temp)){
            // add arr[index] to temp and move to next
            findMax(index + 1, arr, temp + arr[index], maxi);
        }

        // \U0001f501 Choice 2: Skip current string and move to next
        findMax(index + 1, arr, temp, maxi);
    }

public:

    // \U0001f680 Main function
    int maxLength(vector<string>& arr) {
        string temp = ""; // holds the current combination
        int maxi = 0;     // tracks maximum valid length
        findMax(0, arr, temp, maxi); // start recursion
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
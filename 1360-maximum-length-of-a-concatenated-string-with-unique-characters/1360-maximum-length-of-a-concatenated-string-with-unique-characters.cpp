class Solution {
private:
 bool isUnique(string worditself){
    //tofind self uniqueness
    unordered_set<char> st;
    for(auto ch :worditself){
        if(st.count(ch))return false;
        st.insert(ch);
    }
    return true;
 }
 bool findUnique(string searchString , string defalt){
      unordered_set<char> set(defalt.begin(), defalt.end());
      for(auto ch : searchString){
        if(set.count(ch)) return false;
      }
      return true;
 }
 void findMax(int index,vector<string>& arr, string temp,int &maxi){
    if(index == arr.size()){
        if(isUnique(temp)) {
            maxi = max(maxi,(int)temp.size());
        }
        return;
    }

    if(findUnique(arr[index],temp)){
        findMax(index+1,arr,temp + arr[index],maxi);

    }
    findMax(index+1,arr,temp,maxi);
    
 }  

public:
    int maxLength(vector<string>& arr) {
        string temp ="";
        int maxi=0;
        findMax(0,arr,"",maxi);
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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp ;
        temp = nums1 ;
        temp.insert(temp.end(), nums2.begin(), nums2.end());
        sort(temp.begin(), temp.end());
        double ans;
        int low = 0;
        int high = temp.size() -1;
        int mid = (high - low) /2;
        if(temp.size() %2 !=0) {
            ans = temp[mid];
        }
        else{
            double val= (temp[mid] + temp[mid +1] )/ 2.0;
            ans = val;
        }
        return ans;
    }
};
/* vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        for(int i=0;i<n; i++){
            int maxi = arr[i];
            for(int j=i+1; j<n ; j++){
                maxi= max(maxi,arr[j]);
                if(maxi>arr[i]) break;
            }
            if(maxi == arr[i]) result.push_back(maxi);
        }
        return result;
    }*/
// find mx from start to end to all the elem if the maxi is equal to the element which we took
// then push it to the result vector;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        vector<int> result;
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= maxi)
            {
                result.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
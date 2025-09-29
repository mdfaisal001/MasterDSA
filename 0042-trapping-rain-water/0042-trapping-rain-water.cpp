class Solution {

public:
    int trap(vector<int>& height) {

        //to find maximum height from l to r;
        int n = height.size();
        vector<int> maxLeftHeight(n);
        maxLeftHeight[0] = height[0];
        for(int i=1; i<height.size(); i++){
            maxLeftHeight[i] = max(maxLeftHeight[i-1],height[i]);
        }

        // to find maximum height from r to l;

        vector<int> maxRightHeight(n);
        maxRightHeight[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            maxRightHeight[i] = max(maxRightHeight[i+1], height[i]);
        }


        // now find the water which is stored between two walls;

        //maxRightHeight is the maximum left wall and maxRightHeight is the maximum right wall. it gives us the area a wall canhold;
        int total = 0;
        for(int i=0; i<n;i++){
            if(maxLeftHeight[i] > height[i] && height[i] < maxRightHeight[i]){
                total += min(maxLeftHeight[i],maxRightHeight[i]) - height[i];
            }
        }

        return total;
    }
};
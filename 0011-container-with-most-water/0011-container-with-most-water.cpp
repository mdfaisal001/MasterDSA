class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1;
        int Area = 0;
        if(height.size()<2)return 1;
        while(low < high){
            int miniWall = min(height[low] , height[high]);
            int distance = high - low;
            int currArea = miniWall * distance;
            Area = max(Area,currArea);

            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return Area;
    }
};
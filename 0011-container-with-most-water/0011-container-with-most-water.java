class Solution {
    public int maxArea(int[] height) {
        int low =0 , high = height.length-1;
        int maxArea = 0;

        while(low < high){
            int mini = Math.min(height[low],height[high]);
            int area = mini * (high - low);
            maxArea = Math.max(maxArea,area);

            if(height[low] < height[high]) low++;
            else high--;
        }
        return maxArea;
    }
}
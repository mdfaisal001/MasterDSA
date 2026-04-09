class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int low=i+1, high=nums.length-1;

            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0) {
                    result.add(Arrays.asList(nums[i],nums[low],nums[high])); // vec.push_back(temp) or vec.push_back({});
                
                low++;
                high--;
                while(low < high && nums[low] == nums[low -1]) low++;
                while(low < high && nums[high] == nums[high +1]) high--;
             }
                else if(sum < 0) low++;
                else high--;
            }


        }

        return result;
    }
}
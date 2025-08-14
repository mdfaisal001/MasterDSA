class Solution {
    private void findSubset(int index , List<List<Integer>> result , List<Integer> temp, int[] nums){
            result.add(new ArrayList<>(temp));
            if(index >= nums.length) return;

            for(int i=index ; i<nums.length; i++){
                if(i > index && nums[i] == nums[i-1]) continue;
                temp.add(nums[i]);
                findSubset(i+1,result,temp,nums);
                temp.remove(temp.size()-1);

            }
        }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        findSubset(0,result,temp,nums);
        return result;
    }
}
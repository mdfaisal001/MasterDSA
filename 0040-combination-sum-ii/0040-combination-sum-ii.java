class Solution {
    private void findCombinationSum(int index, int[] arr, int target, List<List<Integer>> result, List<Integer> temp){
        if(target < 0) return;
        else if(target ==0){
            result.add(new ArrayList<>(temp));
        }

        for(int i=index; i<arr.length; i++){

            if(i>index && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break;
            temp.add(arr[i]);
            findCombinationSum(i+1,arr,target-arr[i],result,temp);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        findCombinationSum(0,candidates,target,result,temp);
        return result;
    }
}
class Solution {
    private void findCombination(int index, int[] candidates, int target,List<List<Integer>> result, List<Integer> temp){
        if(index == candidates.length){
            if(target == 0){
                result.add(new ArrayList<>(temp));
            }
            return;
        }

        if(target-candidates[index] >=0){
            temp.add(candidates[index]); // pick
            findCombination(index,candidates,target-candidates[index],result,temp);
            temp.remove(temp.size()-1); // backtract
        }
        findCombination(index+1, candidates, target, result, temp); // non pick with the next index
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        findCombination(0,candidates,target,result,temp);
        return result;
    }
}
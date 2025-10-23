class Solution {
    private void findCombination(int index,int k, int target, List<Integer> temp, List<List<Integer>> result){
        if(temp.size() == k && target == 0){
            result.add(new ArrayList<>(temp));
            return;
        }

        for(int i=index ; i< 9; i++){
            temp.add(i+1);
            findCombination(i+1,k,target-(i+1),temp,result);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        findCombination(0,k,n,temp,result);
        return result;
    }
}
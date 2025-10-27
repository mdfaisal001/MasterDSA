class Solution {
    private boolean isPalindrome(int start, int end, String s){
        char[] ch = s.toCharArray();
        while(start <= end){
            if(ch[start] != ch[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    private void findPartition(int index, List<List<String>> result, String s,List<String> temp){
        if(index == s.length()){
            result.add(new ArrayList<>(temp));
            return;
        }

        for(int i=index; i<s.length(); i++){
            if(isPalindrome(index,i,s)){
                String curr = s.substring(index,i+1);
                temp.add(curr);
                findPartition(i+1,result,s,temp);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        findPartition(0,result,s,temp);
        return result;
    }
}
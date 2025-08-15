class Solution {
    HashMap<Character,String> mp = new HashMap();
        public Solution(){
            mp.put('2', "abc");
            mp.put('3', "def");
            mp.put('4', "ghi");
            mp.put('5', "jkl");
            mp.put('6', "mno");
            mp.put('7', "pqrs");
            mp.put('8', "tuv");
            mp.put('9', "wxyz");
        }
    private void findCombination(int index, StringBuilder temp ,List<String> result, String digits){
        
        if(index == digits.length()){
            result.add(temp.toString());
            return;
        }

        String currentString = mp.get(digits.charAt(index));
        for(int i=0; i<currentString.length() ; i++){
            temp.append(currentString.charAt(i));
            findCombination(index+1,temp,result,digits);
            temp.deleteCharAt(temp.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        StringBuilder temp = new StringBuilder();
        List<String> result = new ArrayList();
        if(digits.isEmpty()) return result;
        findCombination(0,temp,result,digits);
        return result;
    }
}
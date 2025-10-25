class Solution {
   HashMap<Character, String> mp = new HashMap<>();
   Solution(){
            mp.put('2', "abc");
            mp.put('3', "def");
            mp.put('4', "ghi");
            mp.put('5', "jkl");
            mp.put('6', "mno");
            mp.put('7', "pqrs");
            mp.put('8', "tuv");
            mp.put('9', "wxyz");
   }

    private void findLetters(int index, StringBuffer temp, List<String> result, String digits){
        if(index == digits.length()){
            result.add(temp.toString());
            return;
        }
        
        String current = mp.get(digits.charAt(index));
        for(char c : current.toCharArray()){
            temp.append(c);
            findLetters(index+1,temp,result,digits); // here index+1 not i+1;
            temp.deleteCharAt(temp.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
       StringBuffer temp = new StringBuffer();
       List<String> result = new ArrayList<>();
       findLetters(0,temp,result,digits);
       return result;
    }
}
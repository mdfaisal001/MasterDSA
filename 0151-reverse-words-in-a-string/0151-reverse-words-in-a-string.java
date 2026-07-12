class Solution {
    private void reverse(int start,int end, StringBuffer s){
        while(start < end){
            char temp =s.charAt(start);
            s.setCharAt(start,s.charAt(end));
            s.setCharAt(end,temp);
            start++;
            end--;
        }
    }
    public String reverseWords(String s) {
        int i=0;
        StringBuffer temp = new StringBuffer();

        while(i < s.length()){
            while(i<s.length() && s.charAt(i) ==' ') i++; //skipping leading zeroes;

            while(i < s.length() && s.charAt(i)!=' '){
                temp.append(s.charAt(i));
                i++;
            }

            while(i<s.length() && s.charAt(i)==' ') i++; //skipping the continuing zeroes;

            if(i <s.length()){
                temp.append(' ');  // adding a single space after each word;
            }
        }

        StringBuffer result = new StringBuffer(temp.toString());

        reverse(0,result.length()-1,result);
        int start = 0;
        for(int end =0;end<=result.length(); end++){

            if(end == result.length() || result.charAt(end)==' '){
                reverse(start,end-1,result);
                start = end+1;
            }
        }


        return result.toString();
    }
}
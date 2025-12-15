class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> st = new Stack<>();
        st.push(s.charAt(0));

        for(int i=1; i<s.length(); i++){
            if(!st.isEmpty() && st.peek() == s.charAt(i)){
                st.pop();
            }
            else st.push(s.charAt(i));
        }

        StringBuffer result  = new StringBuffer();
        while(!st.isEmpty()){
            result.append(st.peek());
            st.pop();
        }
        result.reverse();
        return  result.toString();


    }
}
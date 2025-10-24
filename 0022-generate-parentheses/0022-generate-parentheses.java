class Solution {

    private void findParantheses(int open , int close, StringBuffer pair, int n, List<String> result ){
        if(pair.length() == 2*n){
            String temp = pair.toString();
            result.add(temp);
            return;
        }

        if(open < n) {
            pair.append('(');
            findParantheses(open+1,close,pair,n,result);
            pair.deleteCharAt(pair.length()-1);
        }
        if(close < open) {
            pair.append(')');
            findParantheses(open,close+1,pair,n,result);
            pair.deleteCharAt(pair.length()-1);
        }

    }
    public List<String> generateParenthesis(int n) {
        StringBuffer pair = new StringBuffer();
        int open =0;
        int close = 0;
        List<String> result = new ArrayList<>();
        findParantheses(0,0,pair,n,result);
        return result;
    }
}
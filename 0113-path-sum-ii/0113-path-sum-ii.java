/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void findPath(int sum, TreeNode node,int targetSum, List<List<Integer>> result,List<Integer> temp){
        if(node == null) return;
        sum+=node.val;
        temp.add(node.val);
        if(node.left == null && node.right == null) {
            if(sum == targetSum) result.add(new ArrayList<>(temp) );
        }
        findPath(sum,node.left,targetSum,result,temp);
        findPath(sum,node.right,targetSum,result,temp);
        temp.remove(temp.size()-1);
        
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> container = new ArrayList<>();
        findPath(0,root,targetSum,result,container);
        return result;
    }
}
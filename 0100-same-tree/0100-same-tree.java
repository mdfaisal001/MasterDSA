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
    public boolean isSameTree(TreeNode p, TreeNode q) {
       Queue<Pair<TreeNode,TreeNode>> que = new LinkedList<>();
       if(p == null &&  q== null) return true;
       if(p != null && q !=null) {
            que.add(new Pair<>(p,q));
       }
       else return false;

       while(!que.isEmpty()){
            int size = que.size();

            for(int i=0; i<size; i++){
                TreeNode pNode = que.peek().getKey();
                TreeNode qNode = que.peek().getValue();
                que.poll();

                if(pNode.val != qNode.val) return false;

                if ((pNode.left == null) ^ (qNode.left == null)) return false;
                if ((pNode.right == null) ^ (qNode.right == null)) return false;
                if (pNode.left != null && qNode.left != null) {
                    que.add(new Pair<>(pNode.left, qNode.left));
                }
                if (pNode.right != null && qNode.right != null) {
                    que.add(new Pair<>(pNode.right, qNode.right));
                }
            }
       }

       return true;
    }
}


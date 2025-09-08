class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        boolean flag = true; // true = left-to-right, false = right-to-left

        while (!que.isEmpty()) {
            List<Integer> subList = new ArrayList<>();
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode currNode = que.poll();

                if (flag) subList.add(currNode.val);
                else subList.add(0, currNode.val); // adding elem at left and shifting elem to right almost from (right to left)

                if (currNode.left != null) que.add(currNode.left);
                if (currNode.right != null) que.add(currNode.right);
            }

            flag = !flag;
            result.add(subList);
        }
        return result;
    }
}

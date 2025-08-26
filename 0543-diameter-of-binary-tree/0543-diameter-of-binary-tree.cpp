/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findDiameter(TreeNode* node ,int &maxi){
        if(node == NULL) return 0;
        int left = findDiameter(node->left,maxi);
        int right = findDiameter(node->right,maxi);
        maxi = max(maxi , left+right);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi =0;
        findDiameter(root,maxi);
        return maxi;;
    }
};
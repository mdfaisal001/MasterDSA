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
    int findPath(TreeNode* node,int target , long long sum , int &count){
        if(node == NULL) return 0;
            
        sum+=node->val;
        
        if(sum == target) count++;
        findPath(node->left,target,sum,count);
        findPath(node->right, target,sum,count);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = 0;
        long long sum = 0;
        long long val = findPath(root,targetSum,sum,count);
        val+=pathSum(root->left,targetSum);
        val+=pathSum(root->right,targetSum);
        return val;
    }
};
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
    void findPath(int sum,TreeNode* node, int targetSum , vector<vector<int>> &result, vector<int> &temp){
         if(node == NULL) return;
         sum+=node->val;
         temp.push_back(node->val);

         if(!node->left && !node->right){
             if(sum == targetSum){
                result.push_back(temp);
             }
         }
        
        findPath(sum,node->left,targetSum,result,temp);
        findPath(sum,node->right,targetSum,result,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> container ;
        findPath(0,root,targetSum,result,container);
        return result;
    }
};
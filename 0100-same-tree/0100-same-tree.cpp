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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>que;
        if(p==nullptr && q == nullptr) return true;
        if(p!= nullptr && q!= nullptr) {
            que.push({p,q});
        }
        else{
            return false;
        }

        while(!que.empty()){
            int size = que.size();

            for(int i=0; i<size; i++){
                TreeNode* pNode = que.front().first;
                TreeNode* qNode = que.front().second;
                que.pop();
                if(pNode->val != qNode->val){
                    return false;
                }
                    //
                 if ((pNode->left == nullptr) ^ (qNode->left == nullptr)) return false;
                 if ((pNode->right == nullptr) ^ (qNode->right == nullptr)) return false;

                if(pNode->left != nullptr && qNode->left != nullptr) que.push({pNode->left,qNode->left});
                if(pNode->right!= nullptr && qNode->right != nullptr) que.push({pNode->right,qNode->right});
                
            }
        }
        return true;
    }
};
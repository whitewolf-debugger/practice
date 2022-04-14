/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int tarDat = target->val;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(cloned);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            if(front->val == tarDat){
                return front;
            }
            pendingNodes.pop();
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        return NULL;
    }
};
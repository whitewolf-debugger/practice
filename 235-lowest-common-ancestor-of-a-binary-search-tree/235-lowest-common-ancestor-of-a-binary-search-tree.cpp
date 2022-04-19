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
    bool isAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        queue<TreeNode*> pendingNodes;
        bool sol1=false;
        bool sol2 = false;
        if(root==p) sol1=true;
        if(root==q) sol2=true;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->left!=NULL){
                pendingNodes.push(front->left);
                if(front->left->val==p->val || front->left->val==q->val){
                    if(front->left->val==p->val ){
                        sol1=true;
                    }
                    if( front->left->val==q->val){
                        sol2=true;
                    }
                }
            }
            if(front->right!=NULL){
                if(front->right->val==p->val|| front->right->val==q->val){
                    if(front->right->val==p->val){
                        sol1=true;
                    }
                    if(front->right->val==q->val){
                        sol2=true;
                    }
                }
                pendingNodes.push(front->right);
            }
        }
        return sol1 && sol2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = NULL;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(isAncestor(front,p,q)) ans = front;
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        return ans;
    }
};
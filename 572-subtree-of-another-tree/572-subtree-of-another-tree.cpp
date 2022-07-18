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
    bool equal(TreeNode* root1,TreeNode* root2){
        if(!root2 && root1!=NULL) {
            return false;
        }
        if(!root1 && root2!=NULL) {
            return false;
        }
        if(!root2 && !root1){
            return true;
        }
        if(root1->val!=root2->val){
            return false;
        }
        return equal(root1->left,root2->left) && equal(root1->right,root2->right) ;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->val == subRoot->val){
                if(equal(front,subRoot)) return true;
            }
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        return false;
    }
};
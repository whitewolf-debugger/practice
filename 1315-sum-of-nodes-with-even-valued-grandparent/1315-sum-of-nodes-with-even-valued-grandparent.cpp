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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->left!=NULL){
                pendingNodes.push(front->left);
                if(front->val%2==0){
                    sum+=((front->left->left)?front->left->left->val:0)+((front->left->right)?front->left->right->val:0);
                }
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
                if(front->val%2==0){
                    sum+=((front->right->left)?front->right->left->val:0)+((front->right->right)?front->right->right->val:0);
                }
            }
        }
        return sum;
    }
};
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
    TreeNode* increasingBST(TreeNode* root) {
        priority_queue<int, vector<int>, greater<int>> sol;
        queue<TreeNode*> pendingNodes;
 
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            sol.push(front->val);
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }            
        }
        TreeNode * newRoot = new TreeNode(sol.top());
        sol.pop();
        TreeNode *actual = newRoot;
        while(!sol.empty()){
            TreeNode *child  = new TreeNode(sol.top());
            newRoot->right = child;
            newRoot->left = NULL;
            newRoot=child;
            sol.pop();
        }
        return actual;
    }
};
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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(pq.size()>=k){
              if(pq.top()>front->val){
                  pq.pop();
                  pq.push(front->val);
              }   
            }
            if(pq.size()<k){
                pq.push(front->val);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
        }
        return pq.top();
    }
};
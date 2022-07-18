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
    int SUM(TreeNode* root){
        int sum =0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                sum+=front->val;
                if(front->left!=NULL){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);
                }
            }
        }
        return sum;
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                if(front->left==NULL && front->right==NULL) front->val =0;
                else {
                    front->val = abs((!front->left?0:SUM(front->left))-(!front->right?0:SUM(front->right)));
                    cout<<front->val<<endl;
                }
                if(front->left!=NULL){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);
                }
            }
        }
        return SUM(root);
    }
};
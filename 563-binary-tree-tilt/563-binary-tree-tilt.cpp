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
    //calculates sum of tree using BFS
    int SUM(TreeNode* root){
        int sum =0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            //DO BFS
            int size = pendingNodes.size();
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                //keep on calculating running sum
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
        //DO BFS
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                //front val is abs(left treesum - right treesum)
                front->val = abs((!front->left?0:SUM(front->left))-(!front->right?0:SUM(front->right)));
                if(front->left!=NULL){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);
                }
            }
        }
        //return sum of the final tree 
        return SUM(root);
    }
};
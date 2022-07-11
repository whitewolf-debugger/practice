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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        vector<int> ans;
        if(!root) return ans;
        while(!pendingNodes.empty()){
            int size=pendingNodes.size();
            vector<int> temp;
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                temp.push_back(front->val);
                if(front->left!=NULL){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);
                }
            }
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};
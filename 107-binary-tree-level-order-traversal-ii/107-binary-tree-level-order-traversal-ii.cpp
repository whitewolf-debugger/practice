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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        //if root is null return null
        if(!root) return ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        //DO BFS
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            vector<int> data;
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                //push the root value in data vector
                data.push_back(front->val);
                if(front->left!=nullptr){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);    
                }
            }
            //push the data in ans
            ans.push_back(data);
        }
        //reverse ans  ans return 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
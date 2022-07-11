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
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        //bfs
        while(!pendingNodes.empty()){
            int size=pendingNodes.size();
            //create a temporary vector 
            vector<int> temp;
            while(size--){
                //push all the data level wise in temporary vector
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
            //push the last element of temporary vector in the ans vector 
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};
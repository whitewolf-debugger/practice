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
    void LevelOrder(TreeNode* root,vector<double> &ans){
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            double sum  = 0;
            double count = 0;
            while(size--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                count++;
                sum += front -> val;
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
            double avg  = sum/count;
            ans.push_back(avg);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        LevelOrder(root,ans);
        return ans;
    }
};
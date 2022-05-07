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
    int loothelp(TreeNode* root,unordered_map<TreeNode*,int>& ans){
        //base case if root is NULL return 0
        if(root==NULL){
            return 0;
        }
        //memoising the approach 
        if(ans[root]){
            return ans[root];
        }
        //1st we are picking the value and storing in int pick
        int pick = root->val;
        if(root->left!=NULL){
            //after picking we skip one node and add others root->left->left and root->left->right
            pick+=loothelp(root->left->left,ans)+loothelp(root->left->right,ans);
        }
        if(root->right!=NULL){
            //after picking we skip one node and add others root->right->left and root->right->right
            pick+= loothelp(root->right->left,ans)+loothelp(root->right->right,ans);
        }
        //choice 2 is we donot pick this roots value 
        int notpick = loothelp(root->left,ans)+loothelp(root->right,ans);
        // which will give us max ans if we pick of if we do not pick this 
        return ans[root]=max(pick,notpick);
    }
    int rob(TreeNode* root) {
        //map is used for memoisation 
        unordered_map<TreeNode*,int> ans;
        return loothelp(root,ans);
    }
};
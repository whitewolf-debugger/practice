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
    void dfs(TreeNode* root,int val,int d,int depth) {
        if(!root) return;
        if(d == depth-1) {
            TreeNode *leftchild = root -> left;
            TreeNode *rightchild = root -> right;
            root ->right = new TreeNode(val);
            root -> left = new TreeNode(val);
            root -> right -> right = rightchild;
            root -> left -> left = leftchild;
        } 
        dfs(root ->left,val,d+1,depth);
        dfs(root ->right,val,d+1,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        dfs(root,val,1,depth);
        return root;
    }
};
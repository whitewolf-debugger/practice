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
    void dfs(TreeNode* root,int &count){
        //base case 
        if(!root) return;
        //increase count for every node
        count++;
        ///dfs recursive calls 
        dfs(root->left,count);
        dfs(root->right,count);
    }
    int countNodes(TreeNode* root) {
        //create 
        int count =0;
        dfs(root,count);
        //count has the ans it is passed by reference 
        return count;
    }
};
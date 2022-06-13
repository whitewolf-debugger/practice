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
    void dfs(TreeNode *root,vector<int>& numbers,long int num){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL  && root->right == NULL){
            num = num*10+root->val;
            numbers.push_back(num);
        }
        num = num*10+root->val;
        dfs(root->left,numbers,num);
        dfs(root->right,numbers,num);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> numbers;
        int num = 0;
        dfs(root,numbers,num);
        int sum = 0 ;
        for(int i = 0 ; i<numbers.size();i++){
            sum+=numbers[i];
        }
        return sum;
    }
};
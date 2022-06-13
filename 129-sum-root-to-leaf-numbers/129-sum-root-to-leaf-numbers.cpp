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
        // base case of dfs if root is null return 
        if(root == NULL){
            return ;
        }
        // if we have reached the leaf node then we add the last lumber  = num*10+root->val
        if(root->left == NULL  && root->right == NULL){
            num = num*10+root->val;
            //push the formed number in numbers vector
            numbers.push_back(num);
        }
        // else make number 
        num = num*10+root->val;
        //do dfs 
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
        //return sum of the formed numbers 
        return sum;
    }
};
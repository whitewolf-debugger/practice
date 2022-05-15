class Solution {
public:
    long int ans = 0, tmp = -1;
    void fun(TreeNode* root, int level){
        if(!root)return;
        if(!root->left && !root->right){
            if(level > tmp){
                tmp = level;
                ans = root->val;
            }
            else if(level == tmp)ans += root->val;
        } 
        fun(root->left, level + 1);
        fun(root->right, level + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        fun(root, 0);
        return ans;
    }
};
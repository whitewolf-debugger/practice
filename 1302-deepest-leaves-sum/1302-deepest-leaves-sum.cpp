class Solution {
public:
    long int ans = 0, tmp = -1;
    void dfs(TreeNode* root, int level){
        //base case if root == NULL terminate
        if(!root)return;
        // if it is leaf node 
        if(!root->left && !root->right){
            //if level is more than current max level stored in temp
            if(level > tmp){
                //current max level = level
                tmp = level;
                //ans  = root->val value at that depth
                ans = root->val;
            }
            // if it is the final depth then add root ->val to the previous data at that level
            else if(level == tmp)ans += root->val;
        } 
        //call at left  and increase level
        dfs(root->left, level + 1);
        //call at right and increase level
        dfs(root->right, level + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
class Solution {
public:
    void dfs(TreeNode* root,vector<vector<int>>& ans,vector<int> path,int target){
        if(root == NULL) return;
        if(root->val ==target){
            // if we reached the point where root value = target 
            path.push_back(target);
            // target is pushed inside the path
            if(root->left==NULL && root->right == NULL){
                //path is pushed inside the ans if we are at the leaf node
                ans.push_back(path);
            }
            // if that is not a leaf node then we can check for taget 0 since negetive values may be there
            else{
                // so we do call on both roots left and right
                dfs(root->left,ans,path,0);
                dfs(root->right,ans,path,0);
            } 
            return;
        }
        // of our target is more or less than the root value 
        else{
            // we push the root value in the path
            path.push_back(root->val);
            // do calls for both the parts of the tree right and left and target is target - root value 
            dfs(root->right,ans,path,target-root->val);
            dfs(root->left,ans,path,target-root->val);
            //backtracking by poping the value and discovering other possibilities
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // ans stores the final paths 
        vector<vector<int>> ans;
        //path stores  the required path from root to leaf whose sum = target
        vector<int> path;
        dfs(root,ans,path,targetSum);
        // final paths are stored in ans since ans is called by reference in dfs 
        return ans;
    }
};
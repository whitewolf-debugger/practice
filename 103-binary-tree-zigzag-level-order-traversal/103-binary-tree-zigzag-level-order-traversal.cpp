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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        //if root is null return null 
        if(!root) return ans;
        q.push(root);
        //keep a track of zig zag
        bool rev = false;
        //bfs
        while(!q.empty()){
            int size = q.size();
            vector<int> path;
            //doing dfs using while loop
            while(size--){
                TreeNode* front = q.front();
                path.push_back(front->val);
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
            //reversing the level if needed
            if(rev){
                reverse(path.begin(),path.end());
            }
            //pushing back path in ans
            ans.push_back(path);
            //updating whether we have to reverse next level 
            rev = !rev;
        }
        //return ans
        return ans;
    }
};
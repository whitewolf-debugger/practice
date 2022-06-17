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
    /*
    0 - not covered by camera 
    1 - covered by camera
    2 = has camera
    */
    int dfs(TreeNode* root,int &cam){
        if(root == NULL) return 1;
        int left = dfs(root->left,cam);
        int right = dfs(root->right,cam);
        if(left == 0 || right ==0){
            cam++;
            return 2;
        }
        else if( left == 2 || right == 2){
            return 1;
        }
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        int returned =  dfs(root,cam);
        return returned == 0?cam+1:cam;
        
    }
};
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
        // if the root is null means it is covered by camera so return 1 
        if(root == NULL) return 1;
        int left = dfs(root->left,cam);
        int right = dfs(root->right,cam);
        // if any of the children is not covered add camera there and return 2 (means camera added)
        if(left == 0 || right ==0){
            cam++;
            return 2;
        }
        // if any of the child has camera then return 1 (means this node is covered by that camera)
        else if( left == 2 || right == 2){
            return 1;
        }
        // if that node not 1 or 0 than that node is not visited and not covered so return 0;
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        int returned =  dfs(root,cam);
        
        return returned == 0?cam+1:cam;
        
    }
};
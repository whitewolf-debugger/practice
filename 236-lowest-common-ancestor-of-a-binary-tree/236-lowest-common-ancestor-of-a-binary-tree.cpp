/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case if we reach posn where root is null return NULL
        if(root == NULL) return NULL;
        //if we reach a point where we got left lCA or right lca first we return that root
        if(root->val == p->val || root->val ==q->val){
            return root;
        }
        // get the leftLCA  and the rightLCA 
        TreeNode* leftLCA= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);
        // if both of them are not null means the dta is present in both the sides of means root is the lca
        if( leftLCA!=NULL && rightLCA!=NULL){
            return root;
        }
        // if one of them is LCA return that 
        else if(leftLCA!=NULL){
            return leftLCA;
        }
        else{
            return rightLCA;
        }
    }
};
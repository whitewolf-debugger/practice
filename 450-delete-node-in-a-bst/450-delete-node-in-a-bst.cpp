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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right= deleteNode(root->right,key);
        }
        else{
            if(root->right==NULL && root->left==NULL){
                delete root;
                return NULL;
            }
            else if(root->right== NULL || root->left==NULL){
                if(root->left!=NULL){
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                else{
                    TreeNode * temp = root->right;
                    delete root;
                    return temp;
                }
            }
            else{
                TreeNode *minNode = root->right;
                while(minNode->left!=NULL){
                    minNode = minNode->left;
                }
                int minVal=minNode->val;
                root->val=minVal;
                root->right=deleteNode(root->right,minVal);
            }
        }
        return root;
    }
};
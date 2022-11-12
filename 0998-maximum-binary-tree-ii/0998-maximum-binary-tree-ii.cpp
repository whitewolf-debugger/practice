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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // if root is NULL then we create a newNode and return 
        if(root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        //if value at root is less then we create a new node and attatch the root to its left
        else if(root -> val < val) {
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        } else {
            //other wise if roots value is bigger then we call to roots right for lower values 
            root -> right = insertIntoMaxTree(root -> right , val);
        }
        //return root after insertion
        return root;
    }
};
/*

as said first tree is constructed following below given instructions
1.Create a root node whose value is the maximum value in nums.
2.Recursively build the left subtree on the subarray prefix to the left of the maximum value.
3.Recursively build the right subtree on the subarray suffix to the right of the maximum value.

as mentioned in question val is appended at the end of nums. So our only task is to check whether it is greater than root->val. if its greater we will create a new node with value as val and make the first tree as its left subtree. its its less we will recurse in the right subtree.




*/
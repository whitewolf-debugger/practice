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
    //check for equality of 2 trees 
    bool equal(TreeNode* root1,TreeNode* root2){
        //if either of the root becomes null and other is not null then return false
        if(!root2 && root1!=NULL) {
            return false;
        }
        if(!root1 && root2!=NULL) {
            return false;
        }
        //if both the root are null together return true;
        if(!root2 && !root1){
            return true;
        }
        //if values of root are not same return false
        if(root1->val!=root2->val){
            return false;
        }
        //return for both the right and left
        return equal(root1->left,root2->left) && equal(root1->right,root2->right) ;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //do bfs visit every node
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            //if fronts value is same as the subroots root value then we check for quality if they are equal we return true;
            if(front->val == subRoot->val){
                if(equal(front,subRoot)) return true;
            }
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        //if we have not returned anything till now means the ans is false 
        return false;
    }
};
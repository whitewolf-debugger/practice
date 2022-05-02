class Solution {
public:
    bool isSymmetricTest(TreeNode* root1 , TreeNode* root2){
        if(root1 == NULL && root2 == NULL) //left & right node is NULL 
            return true; 
        
        else if(root1 == NULL || root2 == NULL) //one of them is Not NULL
            return false; 
        
        else if(root1->val!=root2->val) 
            return false;
        
        return isSymmetricTest(root1->left,root2->right) && isSymmetricTest(root1->right,root2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; //Tree is empty
        
        return isSymmetricTest(root->left,root->right);
    }
    
};
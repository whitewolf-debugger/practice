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
    TreeNode* builder(vector<int> &inorder,vector<int> preorder,int preS,int preE,int InS,int InE){
        if(InS>InE || preS>preE){
            return NULL;
        }
        int rootdata = preorder[preS];
        int rootIndex  = -1;
        for(int i=InS;i<=InE;i++){
            if(inorder[i]==rootdata){
                rootIndex = i;
            }
        }
        int linS = InS;
        int linE = rootIndex-1;
        int rinS = rootIndex+1;
        int rinE = InE;
        int lpreS = preS+1; 
        int rpreE = preE; 
        int lpreE = (linE-linS)+lpreS ;
        int rpreS = lpreE+1;
        TreeNode* root = new TreeNode(rootdata);
        root->left = builder(inorder,preorder,lpreS,lpreE,linS,linE);
        root->right = builder(inorder,preorder,rpreS,rpreE,rinS,rinE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         TreeNode* root = builder(inorder,preorder,0,preorder.size()-1,0,inorder.size()-1);
	    return root;
    }
};
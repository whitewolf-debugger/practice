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
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int inS,int inE,int poS,int poE){
        if(inS>inE) return NULL;
        int rootIndex =-1;
        int rootData = postorder[poE];
        for(int i=inS;i<=inE;i++){
            if(inorder[i]==rootData){
                rootIndex = i;
                break;
            }
        }
        int linS=inS;
        int linE=rootIndex-1;
        int rinS=rootIndex+1;
        int rinE=inE;
        int lpoS=poS;
        int lpoE=linE-linS+lpoS;
        int rpoS=lpoE+1;
        int rpoE=poE-1;
        TreeNode* root = new TreeNode(rootData);
        root->left = helper(inorder,postorder,linS,linE,lpoS,lpoE);
        root->right = helper(inorder,postorder,rinS,rinE,rpoS,rpoE);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
/*

 inorder => left root right
            
 postorder => left right root
 lpoE = linE-linS+lpoS


*/
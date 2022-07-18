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
        //ins is inorder start , inE is inorder end and poS is preorder start , poE is preorder end 
        if(inS>inE) return NULL;
        //place -1 in root index 
        int rootIndex =-1;
        //root data in postorder array is at its end 
        int rootData = postorder[poE];
        //loop starts from inorder start and goes till inorder end 
        for(int i=inS;i<=inE;i++){
            //if we found root in inorder array
            if(inorder[i]==rootData){
                //store that index in rootIndex
                rootIndex = i;
                break;
            }
        }
        //left inorder start
        int linS=inS;
        //left inorder end
        int linE=rootIndex-1;
        //right inorder start
        int rinS=rootIndex+1;
        //right inorder end
        int rinE=inE;
        //left preorder start
        int lpoS=poS;
        //left preorder end
        int lpoE=linE-linS+lpoS;
        //right preorder start
        int rpoS=lpoE+1;
        //right preodred end 
        int rpoE=poE-1;
        //create root 
        TreeNode* root = new TreeNode(rootData);
        //attatch left node to left 
        root->left = helper(inorder,postorder,linS,linE,lpoS,lpoE);
        //attatch right node to right
        root->right = helper(inorder,postorder,rinS,rinE,rpoS,rpoE);
        //return root
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
/*

 inorder :       left    root      right
                |    |    |       |     |
              lins linE  rootInd  rinS  rinE
              
              
        int linS=inS;
        int linE=rootIndex-1;
        int rinS=rootIndex+1;
        int rinE=inE;
        
              
 postorder :     left     right    root
                |    |   |     |    |
              lpoS  lpoE rpoS rpoE  poE
              
              
        int lpoS=poS;
        int lpoE=linE-linS+lpoS;
        int rpoS=lpoE+1;
        int rpoE=poE-1;
        
        
        size of left in postorder = lpoE-lpoS
        size of left in inorder =  linE-linS 
        and we know that 
        size of left in inorder =size of left in postorder 
        so  lpoE-lpoS = linE-linS 
        hence , int lpoE=linE-linS+lpoS;
*/
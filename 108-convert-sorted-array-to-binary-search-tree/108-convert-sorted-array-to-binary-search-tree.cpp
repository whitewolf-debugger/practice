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
    TreeNode* createBST(vector<int> & nums , int start , int end){
        //base case is that when start > end we  return NULL as the node
        if(start>end){
            return NULL;
        }
        //The root is at the mid 
        int rootIndex = (start+end)/2;
        // create a root with mid as the data 
        TreeNode* root = new TreeNode(nums[rootIndex]);
        // now we want left child it will be from start to rootIndex-1
        root->left = createBST(nums,start,rootIndex-1);
        //and right child are form rootIndex+1 to end 
        root->right = createBST(nums,rootIndex+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end = nums.size()-1;
        int start =0;
        return createBST(nums,start,end);
    }
};

/*

     1     	 2   	 3   	 4   	 5   	 6  	7
     
[left child from 1 to 3] [rootindex] [right child from 5 to 7]

    1   2   3 
    2 is the root and 1 is left child  3 is right child 
    
    5   6   7
    6 is the root  and 5 is left child 7 is right child
 

*/
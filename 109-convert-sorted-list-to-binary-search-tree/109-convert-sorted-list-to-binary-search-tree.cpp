/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    /*convert linked list to array and then make sorted array to BST*/
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
    TreeNode* sortedListToBST(ListNode* head) {
        //converting linked list to sorted array 
        vector<int> data;
        ListNode* temp = head;
        while(temp!=NULL){
            data.push_back(temp->val);
            temp=temp->next;
        }
        int start =0;
        int end  = data.size()-1;
        TreeNode* root = createBST(data,0,end);
        return root;
    }
};
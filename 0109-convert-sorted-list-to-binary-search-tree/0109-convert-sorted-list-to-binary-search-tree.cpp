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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) {
            //DISCONNECTST THE GRAPH IN 2 HALF 
            //head to node before middle -> null and   middle to end -> null
            prev -> next = NULL;
        }
        //return the middle node which we will make root
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        //base case 
        if(!head) return NULL;
        //get the middle node pointer
        ListNode* middle = middleNode(head);
        //create tree node with value at the middle of linked list
        TreeNode* node = new TreeNode(middle->val);
        if(head == middle) return node; // if there's only one node
        node->left = sortedListToBST(head);
        //right half of BST is from middle -> next as middle element is node and is returned
        node->right = sortedListToBST(middle->next); // pass the node after middle
        return node;
    }
};
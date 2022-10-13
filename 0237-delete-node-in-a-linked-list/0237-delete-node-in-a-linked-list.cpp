/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //keep track of previous of current node 
        ListNode *prev = node;
        while(node != NULL && node -> next != NULL){
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        //make the last node NULL
        prev -> next = NULL;
    }
};
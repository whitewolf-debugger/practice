class Solution {
    ListNode* helper(ListNode* head){
        if(head == NULL){
            return head;
        }
        if(head->next ==NULL){
            return head;
        }
        ListNode*curr = head;
        ListNode * next = head->next;
        ListNode *remaining = helper(next->next);
        next->next  = curr;
        curr->next = remaining;
        return next;
        
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }
};
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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *oddhead = NULL; 
        ListNode *oddtail = NULL;

        ListNode *evenhead = NULL;
        ListNode *eventail = NULL;

        int count = 1;
        ListNode* temp = head;

        while(temp != nullptr) {
            ListNode* node = new ListNode(temp -> val);
            if(count % 2 == 0) {
                if(evenhead == NULL) {
                    evenhead = node;
                    eventail = node;
                } else {
                    eventail -> next = node;
                    eventail = eventail -> next;
                }
            } else {
                if(oddhead == NULL) {
                    oddhead = node;
                    oddtail = node;
                } else {
                    oddtail -> next = node;
                    oddtail = oddtail -> next;
                }
            }
            temp = temp -> next;
            count++;
        }

        oddtail -> next = evenhead;
        return oddhead;
    }
};
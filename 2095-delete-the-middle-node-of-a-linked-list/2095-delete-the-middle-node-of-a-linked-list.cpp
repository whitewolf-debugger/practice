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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        if(count == 1){
            return NULL;
        }
        ListNode* prev =head;
        ListNode* slow = count % 2 == 0 ? head -> next : head;
        ListNode* fast = head;
        while(fast!= NULL && fast -> next != NULL && fast-> next -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast =fast -> next -> next;
        }
        prev -> next = slow -> next;
        return head;
    }
};
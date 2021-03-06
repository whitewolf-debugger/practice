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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode * temp = head;
        int count=1;
        ListNode* fast = head;
        while(temp->next!=NULL){
            count++;
            temp =temp->next;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        // return next of slow pointer if even
        if(count%2==0){
            return slow->next;
        }
        //returns slow pointer if odd number of elements are present
        return slow;
    }
};
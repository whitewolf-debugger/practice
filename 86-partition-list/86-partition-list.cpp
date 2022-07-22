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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* smallhead = new ListNode(0);
        ListNode* smalltail = smallhead;
        ListNode* bighead = new ListNode(0);
        ListNode *bigtail =bighead;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                    smalltail->next = temp;
                    smalltail = temp;
            }
            else{
                    bigtail->next = temp;
                    bigtail = temp;
            }
            temp=temp->next;
        }
        bigtail->next = NULL;
        smalltail->next = bighead->next;
            
        return smallhead->next;
    }
};
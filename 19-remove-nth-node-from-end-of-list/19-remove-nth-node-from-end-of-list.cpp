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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size =0;
        ListNode *ptr = head;
        ListNode *temp = head;
        ListNode *temp2 = head;
        int count =0;
        while(temp2!=NULL){
            temp2 = temp2->next;
            count++;
        }
        if(count==n){
            head=head->next;
            return head;
        }
        while(size<(count-n)){
            ptr=ptr->next;
            size++;
        }
        while(temp->next!=ptr){
            temp=temp->next;
        }
        temp->next = ptr->next;
        return head;
    }
};
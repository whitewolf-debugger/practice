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
        if(head==NULL){
            return NULL;
        }
        int count=1;
        ListNode* oddhead = NULL;
        ListNode* evenhead = NULL;
        ListNode* oddtail =NULL;
        ListNode* eventail = NULL;
        while(head!=NULL){
            if(count%2!=0){
                if(oddhead==NULL){
                    oddhead = head;
                    oddtail=head;
                }
                else{
                    oddtail->next = head;
                    oddtail=oddtail->next;          
                }
            }
            else{
               if(evenhead==NULL){
                    evenhead = head;
                    eventail= head;
                }
                else{
                    eventail->next = head;
                    eventail= eventail->next;          
                } 
            }
            count++;
            head = head->next;
        }
        oddtail->next = evenhead;
        if(eventail!=NULL){
            eventail->next = NULL;
        }
        return oddhead;
    }
};
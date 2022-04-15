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
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);
        int ans=0;
        int count=0;
        int size =0;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            int smallcal = (temp->val)*2;
            ans+=(smallcal>0)?pow(smallcal,count):0;
            count++;
            temp=temp->next;
            size++;
        }
        if(size==1){
            if(head->val==0){
                return 0;
            }
        }
        return ans;
    }
};
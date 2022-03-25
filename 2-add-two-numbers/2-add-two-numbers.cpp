class Solution {
public:
    ListNode *reverse(ListNode* head){
        ListNode *currptr = head;
        ListNode *prevptr = NULL;
        ListNode *nextptr = NULL;
        while(currptr!=NULL){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 =  reverse(l1);
        // l2 =  reverse(l2);
        ListNode *temp;
        int sum=0;
        int carry=0;
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        while(l1 !=NULL || l2!=NULL){
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = (sum>=10)?1:0;
            sum =sum%10;
            temp = new ListNode(sum);
            if(newhead == NULL){
                newhead = temp;
                newtail = temp;
            }
            else{
                newtail->next = temp;
                newtail = temp;
            }
            if(l1 != NULL){
               l1 = l1 ->next;
            } 
            if(l2 != NULL){
                l2 = l2 -> next;
            } 
        }
        if(carry>0){
            temp = new ListNode(carry);
            newtail->next = temp;
            newtail = temp;
        }
        newtail->next = NULL;
        // newhead = reverse(newhead);
        return newhead;
    }
};
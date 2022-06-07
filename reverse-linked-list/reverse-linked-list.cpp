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
    ListNode* reverse(ListNode* prev,ListNode * curr,ListNode* next){
        if(curr==NULL){
            return prev;
        }
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        return reverse(prev,curr,next);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        return reverse(prev,head,NULL);
    }
};
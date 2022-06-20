/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL && seen.find(temp)==seen.end()){
            seen.insert(temp);
            temp = temp->next;
        }
        if(!temp) return NULL;
        return temp;
    }
};
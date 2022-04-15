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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
       vector<int> v;
        while(head!=NULL){
            if(head->val!=val){
                v.push_back(head->val);
            }
            head = head->next;
        }
        if(v.empty()){
            return NULL;
        }
        ListNode* newhead = new ListNode(v[0]);
        ListNode* newtail = newhead;
        for(int i=1;i<v.size();i++){
            ListNode *node = new ListNode(v[i]);
            newtail->next = node;
            newtail = newtail->next;
        }
        return newhead;
    }
};
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
    ListNode* sortList(ListNode* head) {
        vector<int> data;
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp!=NULL){
            data.push_back(temp->val);
            temp = temp->next;
        }
        sort(data.begin(),data.end());
        int i =0;
        while(temp2!=NULL && i<data.size()){
            temp2->val =data[i];
            temp2 = temp2->next;
            i++;
        }
        return head;
    }
};
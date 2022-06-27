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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp = head;
        vector<int> data;
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        for(auto& a:mp){
            if(a.second==1){
                data.push_back(a.first);
            }
        }
        sort(data.begin(),data.end());
        for(int i=0;i<data.size();i++){
            ListNode* newNode = new ListNode(data[i]);
            if(newhead==NULL){
                newhead = newNode;
                newtail = newNode;
            }
            else{
                newtail->next = newNode;
                newtail = newNode;
            }
        }
        return newhead;
    }
};
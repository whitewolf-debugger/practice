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
        //create map of all the data and its occurances 
        unordered_map<int,int> mp;
        ListNode* temp = head;
        vector<int> data;
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        while(temp!=NULL){
            //frequency of all the data
            mp[temp->val]++;
            temp = temp->next;
        }
        for(auto& a:mp){
            //if data is present only once 
            if(a.second==1){
                //push the value in data
                data.push_back(a.first);
            }
        }
        //sort the vector data
        sort(data.begin(),data.end());
        //create new linked list with sorted vector
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
        //return head of new linkedlist
        return newhead;
    }
};
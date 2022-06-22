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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ///this is for creating a new linkedlist
        ListNode *head = NULL;
        ListNode *tail = NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i =0;i<lists.size();i++){
            //pushing data of linkedlist in priorityqueue
            while(lists[i]!=NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            if(head ==NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail ->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};
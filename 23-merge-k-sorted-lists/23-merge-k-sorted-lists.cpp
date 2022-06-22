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
        ListNode *head = NULL;
        ListNode *tail = NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> data;
        for(int i =0;i<lists.size();i++){
            while(lists[i]!=NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        while(!pq.empty()){
            data.push_back(pq.top());
            pq.pop();
        }
        for(int i=0;i<data.size();i++){
            ListNode* newNode = new ListNode(data[i]);
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
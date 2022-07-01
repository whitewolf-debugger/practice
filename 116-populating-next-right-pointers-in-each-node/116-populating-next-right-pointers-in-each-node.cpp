/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            Node* prev =NULL;
            while(size--){
                Node* front = pendingNodes.front();
                pendingNodes.pop();
                if(prev!=NULL) prev->next = front;
                prev = front;
                if(front->left!=NULL){
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    pendingNodes.push(front->right);
                }
            }
        }
        return root;
    }
};
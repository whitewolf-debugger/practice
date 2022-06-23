/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> sol;
        if(!root) return sol;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int n = pendingNodes.size();
            vector<int> temp;
            //since we have to return data like [[1],[3,2,4],[5,6]] so we are usig while loop 
            while(n--){
                Node* front = pendingNodes.front();
                pendingNodes.pop();
                temp.push_back(front->val);
                for(int i=0;i<front->children.size();i++){
                    pendingNodes.push(front->children[i]);
                }
            }
            //push temp in sol
            sol.push_back(temp);
        }
        return sol;
    }
};
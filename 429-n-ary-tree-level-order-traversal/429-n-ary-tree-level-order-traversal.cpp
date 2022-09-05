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
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> pendingNodes;
        vector<int> level;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            level.clear();
            while(size--){
                Node* front = pendingNodes.front();
                level.push_back(front -> val);
                pendingNodes.pop();
                for(int i = 0; i < front -> children.size();i++){
                    pendingNodes.push(front->children[i]);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
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
        
        //check ifthe root is NULL then return an empty vector
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> pendingNodes;
        vector<int> level;
        //push the root in pendingNodes queue
        pendingNodes.push(root);
        //while pendingNode has data in it 
        while(!pendingNodes.empty()){
            //get the size of the queue pendingNodes
            int size = pendingNodes.size();
            level.clear();
            while(size--){
                //get the front node from pendingNodes
                Node* front = pendingNodes.front();
                //push the value in level vector 
                level.push_back(front -> val);
                //pop the front node
                pendingNodes.pop();
                
                //peush all the children of current node from left ti right in the pendingNodes
                for(int i = 0; i < front -> children.size();i++){
                    pendingNodes.push(front->children[i]);
                }
            }
            //push the level in the ans
            ans.push_back(level);
        }
        //return ans
        return ans;
    }
};
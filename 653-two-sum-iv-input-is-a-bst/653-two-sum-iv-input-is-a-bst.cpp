/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        vector<int> v;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode * front  = pendingNodes.front();
            pendingNodes.pop();
            //insert the elements of the tree in the vector and set 
            st.insert(front->val);
            v.push_back(front->val);
            //bfs
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        //search all the elements of tree if sum == k 
        for(auto x: v){
            int diff = k-x;
            //erase x so that we donot encounter error in case [1] sum =2 where 1+1 can be 2
            st.erase(x);
            if(st.find(diff)!=st.end()){
                //return true if we got the diff and x is there in the set
                return true;
            }
            //re insert that element 
            st.insert(x);
        }
        //ans is false otherwise 
        return false;
    }
};
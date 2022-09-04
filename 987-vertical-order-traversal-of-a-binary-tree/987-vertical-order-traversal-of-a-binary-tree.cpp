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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodeMap;
        queue<pair<TreeNode*,pair<int,int>>> pendingNodes;
        pendingNodes.push({root,{0,0}});
        
        while(!pendingNodes.empty()){
            TreeNode* currNode = pendingNodes.front().first;
            int x = pendingNodes.front().second.first;
            int y = pendingNodes.front().second.second;
            pendingNodes.pop();
            nodeMap[x][y].insert(currNode->val);
            
            if(currNode -> left != NULL){
                pendingNodes.push({currNode -> left,{x-1,y+1}});
            }
            if(currNode -> right != NULL){
                pendingNodes.push({currNode -> right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto x: nodeMap){
            vector<int> col;
            for(auto y:x.second){
                for(auto element: y.second){
                    col.push_back(element);
                }
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
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
        // initially the coordinates are {0,0}
        pendingNodes.push({root,{0,0}});
        
        //while the queue is not empty 
        while(!pendingNodes.empty()){
            
            //take the current front node 
            TreeNode* currNode = pendingNodes.front().first;
            
            //store the current x and y coordinates 
            int x = pendingNodes.front().second.first;
            int y = pendingNodes.front().second.second;
            
            //remove the front element of the queue 
            pendingNodes.pop();
            
            //add the current node rto x and y in the map 
            nodeMap[x][y].insert(currNode->val);
            
            // for left x-1 and y+1 as we go down along with going to the left 
            if(currNode -> left != NULL){
                pendingNodes.push({currNode -> left,{x-1,y+1}});
            }
            // for right x+1 and y+1 as we go down along with going to the right
            if(currNode -> right != NULL){
                pendingNodes.push({currNode -> right,{x+1,y+1}});
            }
        }
        
        //create the ans vector by pushing all the element of given set of x and y in ans array
        vector<vector<int>> ans;
        for(auto x: nodeMap){
            vector<int> col;
            for(auto y:x.second){
                for(auto element: y.second){
                    col.push_back(element);
                }
            }
            
            //push the currant column in the ans 
            ans.push_back(col);
        }
        //return the ans
        return ans;
    }
};
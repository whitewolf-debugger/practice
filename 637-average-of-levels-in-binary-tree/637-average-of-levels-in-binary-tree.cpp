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
    void LevelOrder(TreeNode* root,vector<double> &ans){
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            //sum stores the sum for every level 
            double sum  = 0;
            //count counts the sum for every level 
            double count = 0;
            //we use size to travel the entire level and size is updated every time 
            while(size--){
                //get the front of the queue 
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                //count the number of elements 
                count++;
                //count the sum of the level
                sum += front -> val;
    
                //push the left in the queue if it is there 
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                //push the right in the queue if it exists 
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
            //calculate the average of the level
            double avg  = sum/count;
            //push the average in the level 
            ans.push_back(avg);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        //ans stores the sum of the level 
        vector<double> ans;
        //do the level order traversal 
        LevelOrder(root,ans);
        
        //return the ans vector 
        return ans;
    }
};
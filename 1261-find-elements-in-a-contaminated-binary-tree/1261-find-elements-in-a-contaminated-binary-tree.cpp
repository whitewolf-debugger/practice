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
class FindElements {
public:
    TreeNode* controot;
    FindElements(TreeNode* root) {
        int i=0;
        controot=root;
        controot->val=0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(controot);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            int x = front->val;
            pendingNodes.pop();
            if(front->left!=NULL){
                front->left->val= ((2*x)+1);
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                front->right->val = ((2*x)+2);
                pendingNodes.push(front->right);
            }
        }
    }
    
    bool find(int target) {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(controot);
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            if(front->val==target){
                return true;
            }
            pendingNodes.pop();
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
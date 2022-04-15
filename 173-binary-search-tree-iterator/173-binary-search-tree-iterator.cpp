class BSTIterator {
public:
    vector<int> res;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    int index = 0;
    int size = res.size();
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        return res.size()>index;
    }
};
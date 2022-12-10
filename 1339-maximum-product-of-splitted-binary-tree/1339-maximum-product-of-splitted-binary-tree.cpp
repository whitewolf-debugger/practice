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
    int MOD = 1e9 + 7;
    
    //gets the sum of the tree
    int subtreeSum(TreeNode * root) {
        if(!root) return 0;
        int leftSum = subtreeSum(root -> left);
        int rightSum = subtreeSum(root -> right);
        return root -> val + leftSum + rightSum;
    }
    
    //gets the ans where ans is passed as reference 
    long long getAns(TreeNode* root , long long &totalSum ,long long &ans) {
        if(!root) return 0;
        long long left = getAns(root -> left, totalSum, ans);
        long long right = getAns(root -> right, totalSum ,ans);
        //get the sum of current subree 
        long long currHalf = (root -> val + left + right) % MOD;
        //sum of remaining subtree is total - curr 
        long long remainingHalf = (totalSum - currHalf) % MOD;
        //get the ans 
        ans = max(ans , (currHalf * remainingHalf));
        return currHalf;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = subtreeSum(root);

        long long ans = 0;
        getAns(root , totalSum,ans);
        //that you need to maximize the answer before taking the mod and not after taking it.
        return ans % MOD;

    }
};
/*



*/
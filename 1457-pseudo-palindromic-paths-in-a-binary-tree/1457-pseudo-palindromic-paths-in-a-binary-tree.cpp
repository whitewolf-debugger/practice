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
    void backtracking(TreeNode* root,vector<int> &freq, int& count){
        if(!root) return;
        if(root -> left == NULL && root -> right == NULL){
            freq[root -> val]++;
            int numOddFreq = 0;
            for(int i =0; i < 10; i++){
                if(freq[i]  % 2 != 0){
                    numOddFreq ++;
                }
            }
            if(numOddFreq <= 1){
                count++;
            }
            freq[root -> val]--;
        }
        freq[root -> val]++;
        if(root -> left != NULL){
            backtracking(root -> left,freq,count);
        }
        if(root -> right != NULL){
            backtracking(root -> right,freq,count);
        }
        freq[root -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans = 0;
        backtracking(root,freq,ans);
        return ans;
    }
};
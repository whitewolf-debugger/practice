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
        //if we are at the null position return null
        if(!root) return;
        
        //if we are at the leaf node 
        if(root -> left == NULL && root -> right == NULL){
            //add the frequency of current node 
            freq[root -> val]++;
            //count the number of element with odd frequency
            int numOddFreq = 0;
            for(int i =0; i < 10; i++){
                if(freq[i]  % 2 != 0){
                    numOddFreq ++;
                }
            }
            //if number of element with odd frequency are atmost 1 then it is palindrome so increase  count
            if(numOddFreq <= 1){
                count++;
            }
            //remove the frequency of current node backtracking step
            freq[root -> val]--;
        }
        //increase the frequency of the current element 
        freq[root -> val]++;
        if(root -> left != NULL){
            backtracking(root -> left,freq,count);
        }
        if(root -> right != NULL){
            backtracking(root -> right,freq,count);
        }
         //decrease the frequency of the current element backtracking step
        freq[root -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans = 0;
        backtracking(root,freq,ans);
        return ans;
    }
};
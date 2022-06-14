class Solution {
public:
    int minDistance(string word1, string word2,vector<vector<int>> &memo){
        int m = word1.size();
        int n = word2.size();
        int ans;
        // base case either of the 2 word is of 0  size so no. of change will be max of both string
        if(word1.size()==0 || word2.size()==0){
            return max(word1.size(),word2.size());
        }
        //memoization
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(word1[0]==word2[0]){
        // case 2 when 1st letter both word are same then remove then 
           ans= minDistance(word1.substr(1),word2.substr(1),memo);
        }
        else{
            // if not same then a is 1+ remove 1st letter from word 1 
            int a =minDistance(word1.substr(1),word2,memo)+1;
            // case 2 remove 1st letter form 2nd word and add 1 since 1 word is not same 
            int b =minDistance(word1,word2.substr(1),memo)+1;
            // ans  is min of both 
            ans = min(a,b);
        }
        // memoize
        memo[m][n] = ans;
        return memo[m][n];
    }
    int minDistance(string word1, string word2) {
        int m  = word1.size();
        int n = word2.size();
        //memoizinf with mxn vector
        vector<vector<int>> memo(m+3,vector<int>(n+3,-1));
        return minDistance(word1,word2,memo);
    }
};
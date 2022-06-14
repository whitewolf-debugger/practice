class Solution {
public:
    int minDistance(string word1, string word2,vector<vector<int>> &memo){
        int m = word1.size();
        int n = word2.size();
        int ans;
        if(word1.size()==0 || word2.size()==0){
            return max(word1.size(),word2.size());
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(word1[0]==word2[0]){
           ans= minDistance(word1.substr(1),word2.substr(1),memo);
        }
        else{
            int a =minDistance(word1.substr(1),word2,memo)+1;
            int b =minDistance(word1,word2.substr(1),memo)+1;
            ans = min(a,b);
        }
        memo[m][n] = ans;
        return memo[m][n];
    }
    int minDistance(string word1, string word2) {
        int m  = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m+3,vector<int>(n+3,-1));
        return minDistance(word1,word2,memo);
    }
};
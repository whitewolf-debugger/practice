class Solution {
public:
    bool dfs(string s1, string s2, string s3,int i,int j,vector<vector<int>> &memo){
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        if(memo[i][j]!=-1) return memo[i][j];
        bool op1 = false;
        bool op2 = false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            op1 =dfs(s1,s2,s3,i+1,j,memo);
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            op2= dfs(s1,s2,s3,i,j+1,memo);
        }
        return memo[i][j] = op1||op2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
		    return false;   
        }
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        int i=0;
        int j=0;
        return dfs(s1,s2,s3,i,j,memo);
    }
};
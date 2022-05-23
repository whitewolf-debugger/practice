class Solution {
public:
    int helper(vector<string>& str,int m,int n,int index,vector<vector<vector<int>>>& dp){
        if(m<0 || n<0|| index >= str.size()){
            return 0;
        }
        if(dp[index][m][n]!=-1) return dp[index][m][n];
        int num_zeros = count(str[index].begin(),str[index].end(),'0');
        int num_ones = str[index].size()-num_zeros;
        if(num_zeros <= m && num_ones<=n){
            int choose = 1+helper(str,m-num_zeros,n-num_ones,index+1,dp);
            int notchoose = helper(str,m,n,index+1,dp);
            return dp[index][m][n]=max(choose,notchoose);
        }
        else{
          return dp[index][m][n]=helper(str,m,n,index+1,dp);  
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(size(strs), vector<vector<int> >(m + 1, vector<int>(n + 1,-1)));
        return helper(strs,m,n,0,dp);
    }
};
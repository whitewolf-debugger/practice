class Solution {
public:
    int helper(vector<string>& str,int m,int n,int index,vector<vector<vector<int>>>& dp){
        //base case when we have taken strings with required numbers of zeros and ones 
        if(m<0 || n<0|| index >= str.size()){
            return 0;
        }
        //memoizing the soln with 3d vector 
        if(dp[index][m][n]!=-1) return dp[index][m][n];
        //calulates number of zeros in the string at current index
        int num_zeros = count(str[index].begin(),str[index].end(),'0');
        //calculates number of ones in the string at currrent index
        int num_ones = str[index].size()-num_zeros;
        //if number of zeros  and ones in the string is less than the amt required 
        if(num_zeros <= m && num_ones<=n){
            //then we have 2 options to chose or not chose the string
            int choose = 1+helper(str,m-num_zeros,n-num_ones,index+1,dp);
            int notchoose = helper(str,m,n,index+1,dp);
            //we will calculate the chose and not chose both get the max since we want max size substring
            return dp[index][m][n]=max(choose,notchoose);
        }
        else{
            // if the number of zeros and ones are more than what we need then move forward to the next index
          return dp[index][m][n]=helper(str,m,n,index+1,dp);  
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(size(strs), vector<vector<int> >(m + 1, vector<int>(n + 1,-1)));
        return helper(strs,m,n,0,dp);
    }
};
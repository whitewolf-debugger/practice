class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> output(m+1,vector<int>(n+1));
        for(int i = 0;i<=m;i++){
            output[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            output[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[m-i]==text2[n-j]){
                    output[i][j]=1+output[i-1][j-1];
                }
                else{
                    output[i][j]= max(output[i-1][j-1],max(output[i-1][j],output[i][j-1]));
                }
            }
        }
        return output[m][n];
    }
};
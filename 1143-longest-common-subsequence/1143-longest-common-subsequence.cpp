class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //i represents the size of text 1 
        //j represents size of text 2 
        //m is size of text1 
        //n is zie of text 2 
        vector<vector<int>> output(m+1,vector<int>(n+1));
        for(int i = 0;i<=m;i++){
            output[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            output[0][j]=0;
        }
        //we iterate from 1,1 sice 0,j and i,0 all rows are filled with 0
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                /* consider a b c d e f
                    and     x y z
                    i= 2 j=1 means 
                    0 1 2 3  4 5 
                    a b c d |e f size = 6 = m
                    (abcd is removed 1st is e)
                    0 1  2
                    x y |z   size = 3 = n
                    (xy is removed now z is at first)
                    index of z is n-j = 3-1 =2
                    index of e = m-i = 6-2 = 4
                */
                if(text1[m-i]==text2[n-j]){
                    //if the letters at that index are same then add 1 to output[i-1][j-1]
                    output[i][j]=1+output[i-1][j-1];
                }
                else{
                    //else consider 3 cases ex i=3 j=2,  i=3 j=3, i=2 j=3 and take max of it 
                    int x = output[i-1][j];
                    int y = output[i-1][j-1];
                    int z = output[i][j-1];
                    output[i][j]= max(x,max(y,z));
                }
            }
        }
        //reutrn output[m][n] which has ans
        return output[m][n];
    }
};
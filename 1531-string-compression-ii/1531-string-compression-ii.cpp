int dp[101][101][27][101];
class Solution {
public:
string str;
int f(int ind , int k , int prev , int len)
{
    if(k<0)
        return INT_MAX;

    if(ind>=str.size())
        return 0;
    
    if(dp[ind][k][prev][len]!=-1)
        return dp[ind][k][prev][len] ;
    
    int del=f(ind+1 , k-1 , prev , len);
    int take=0;
    if(str[ind]-'a' == prev)
    {
        if(len==1 || len==9 || len==99)
            take+=1;
        
        take = take + f(ind+1,k,prev,len+1);
    }
    
    else
    {
        take=1+f(ind+1,k,str[ind]-'a',1);
    }
    
    return dp[ind][k][prev][len]=min(del,take);
}

int getLengthOfOptimalCompression(string s, int k) {
    str=s;
    memset(dp,-1,sizeof(dp));
    return f(0,k,26,0);
}
};
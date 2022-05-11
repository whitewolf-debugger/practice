class Solution {
public:
    int countVowelStrings(int n) {
        
        int sol = (n+4)*(n+3)*(n+2)*(n+1)/24;
        return sol;
        //return dfs(n,0);
    }
};
/*
    4 bars 
    n= number of woves 
    if n=5 
    question is place n stars and 4 bars in n+4 size strings 
    its 
    (n+4)!/4!*(n)!;
    simplify n=5
     9!/(5! 4!)
    we can generalize it to
    (n+4)*(n+3)*(n+2)*(n+1)/24
    viz our ans
*/
class Solution {
public:
    int countVowelStrings(int n) {    
        int sol = (n+4)*(n+3)*(n+2)*(n+1)/24;
        return sol;
        //return dfs(n,0);
    }
};
/*
    ((num of vowes = 5)-1)=4 bars 
    n=size given
    question is place n stars and 4 bars in n+4 size strings 
    its 
    (n+4)!/4!*(n)!;
    simplify n=5 if n=5 
     9!/(5! 4!)
    we can generalize it to
    (n+4)*(n+3)*(n+2)*(n+1)/24
    viz our ans
*/
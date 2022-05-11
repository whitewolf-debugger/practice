class Solution {
    // int dfs(int n,int i){
    //     if(n ==0){
    //         return 1;
    //     }
    //     int ret =0;
    //     for(int j = i;j<5;j++){
    //         ret += dfs(n-1,j);
    //     }
    //     return ret;
    // }
public:
    int countVowelStrings(int n) {
        
        int sol = (n+4)*(n+3)*(n+2)*(n+1)/24;
        return sol;
        //return dfs(n,0);
    }
};
/*

  9!/(5! 4!)
  (n+4)*(n+3)*(n+2)*(n+1)/24
*/
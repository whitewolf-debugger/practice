class Solution {
    int dfs(int n,int i){
        if(n ==0){
            return 1;
        }
        int ret =0;
        for(int j = i ; j<5;j++){
            ret += dfs(n-1,j);
        }
        return ret;
    }
public:
    int countVowelStrings(int n) {
        return dfs(n,0);
    }
};
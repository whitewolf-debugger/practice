class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                paths[i][j] = paths[i-1][j]+paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};
/*
    place 1 in every  index since we want to fill 1st row and 1st column with 1 
    now 
    1 1 1 1
    1 2 3 4
    1 3 6 10
    1 4 10 20
    to reach end 20 ways are there 
    since 
    number of ways to reach [i][j] =  number of ways to reach[i-1][j]+ number of ways to reach[i][j-1];
*/
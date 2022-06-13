class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        for(int r = 1 ; r < rows ;r++ ){
            int n  = triangle[r].size();
            for(int i = 0 ; i<n;i++){
                if(i == 0){
                    triangle[r][i]+= triangle[r-1][i];
                }
                else if(i==n-1){
                    triangle[r][i]+=triangle[r-1][i-1];
                }
                else{
                    triangle[r][i]+=min(triangle[r-1][i],triangle[r-1][i-1]);
                }
            }           
        }  
        int mn = INT_MAX;
        for(int i = 0 ;i<triangle[rows-1].size();i++){
            mn = min(triangle[rows-1][i],mn);
        }
        return mn;
    }
};
/*

iterate through every row put triangle[row][col]+ = min(triangle[row-1][col],triangle[row-1][col-1])
if col  == 0  then put triangle[r][i]+= triangle[r-1][i];
if i==n-1 then put triangle[r][i]+=triangle[r-1][i-1];
and ans is minimum element of last row


*/
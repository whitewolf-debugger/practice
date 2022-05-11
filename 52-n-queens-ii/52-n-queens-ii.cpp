class Solution {
public:
    bool isPlacable(int n,int row,int col,vector<vector<int>>& board ){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]==1){
                return false;
            }
        }
        for(int i = row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]==1){
                return false;
            }
            
        }
        for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
    }
    void nQueenHelper(int n,int row,int &count,vector<vector<int>>& board){
        if(row == n){
            count++;
            return;
        }
        for(int j=0;j<n;j++){
            if(isPlacable(n,row,j,board)){
                board[row][j]=1;
                nQueenHelper(n,row+1,count,board);
                board[row][j]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int  count =0;
        vector<vector<int>> board(n+3,vector<int>(n+3,0));
        nQueenHelper(n,0,count,board);
        return count;
    }
};
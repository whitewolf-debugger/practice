class Solution {
public:
    bool isPlacable(int n,int row,int col,vector<vector<int>>& board ){
        for(int i=row-1;i>=0;i--){
            //checking for column wheteher queen is present above
            if(board[i][col]==1){
                return false;
            }
        }
        //checking for upper left
        for(int i = row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]==1){
                return false;
            }
            
        }
        //checking for upper right
        for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        //no queens can attack at this position so return true
        return true;
    }
    void nQueenHelper(int n,int row,int &count,vector<vector<int>>& board){
        if(row == n){
            count++;
            return;
        }
        for(int j=0;j<n;j++){
            //we can place queen at [row][j] 
            if(isPlacable(n,row,j,board)){
                //if we can place then we set queen at than position
                board[row][j]=1;
                //discover all possibilities after placing the queen at [row][j] 
                nQueenHelper(n,row+1,count,board);
                //then we remove that queen and place queen at different place and discover possibility
                board[row][j]=0;
            }
        }
    }
    int totalNQueens(int n) {
        //counts the total number of answers 
        int  count =0;
        //creating board
        vector<vector<int>> board(n+3,vector<int>(n+3,0));
        // call nQueenHelper 
        nQueenHelper(n,0,count,board);
        //return count which has answer
        return count;
    }
};
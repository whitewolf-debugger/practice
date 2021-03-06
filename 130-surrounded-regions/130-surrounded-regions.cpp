class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j, int ROWS,int COLS){
        if(i<0 || j<0 || i>=ROWS || j>=COLS || board[i][j]!='O'){
            return;
        }
        board[i][j]='B';
        dfs(board,i+1,j,ROWS,COLS);
        dfs(board,i-1,j,ROWS,COLS);
        dfs(board,i,j+1,ROWS,COLS);
        dfs(board,i,j-1,ROWS,COLS);
    }
    void solve(vector<vector<char>>& board) {
        //Iterate over boundaries to find any 'O' connected to boundary and mark them 'B' using DFS.
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,i,0,m,n);
        }
        for(int i=0;i<m;i++){
            dfs(board,i,n-1,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(board,0,i,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(board,m-1,i,m,n);
        }
        //The Cell which is still 'O' doesn't connected to boundary therefore it is surrounded by "X".
        //Convert all "B" to "O" because they are on boundary hence can be surrounded and mark rest of the cells "X". 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='B'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
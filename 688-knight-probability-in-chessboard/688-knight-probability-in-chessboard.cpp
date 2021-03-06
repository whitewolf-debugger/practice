class Solution {
public:
    double dfs(int x,int y,int ROWS,int COLS,int moves,vector<vector<vector<double>>> &memo){
        //return 0 when we move out of the boundary 
        if(x<0 || y<0 || x>=ROWS ||y>=COLS){
            return 0;
        }
        //return 1 weh we are in board and we are out of the moves 
        if(moves<=0) return 1;
        if(memo[x][y][moves]!=-1) return memo[x][y][moves];
        //all the moves which we can do 
        double move1  = dfs(x-2,y-1,ROWS,COLS,moves-1,memo);
        double move2  = dfs(x-2,y+1,ROWS,COLS,moves-1,memo);
        double move3  = dfs(x-1,y+2,ROWS,COLS,moves-1,memo);
        double move4  = dfs(x+1,y+2,ROWS,COLS,moves-1,memo);
        double move5  = dfs(x+2,y+1,ROWS,COLS,moves-1,memo);
        double move6  = dfs(x+2,y-1,ROWS,COLS,moves-1,memo);
        double move7  = dfs(x+1,y-2,ROWS,COLS,moves-1,memo);
        double move8  = dfs(x-1,y-2,ROWS,COLS,moves-1,memo);
        // for each cell there are 8 possible moves, so probablity will be no. of successfull moves / 8
        double probability = (move1+move2+move3+move4+move5+move6+move7+move8)/8;
        return memo[x][y][moves]=probability;
    }
    double knightProbability(int n, int k, int row, int column) {
        //memoize using 3D vector 
        vector<vector<vector<double>>> memo(30,vector<vector<double>>(30,vector<double>(105,-1)));
        return dfs(row,column,n,n,k,memo);
    }
};
/*
  all the direction of movements 
  
  (x-2,y-1),(x-1,y-2),(x+1,y-2),(x+2,y-1),(x+2,y+1),(x+1,y+2),(x-1,y+2),(x-2,y+1)





*/
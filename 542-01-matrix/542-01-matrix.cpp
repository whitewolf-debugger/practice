class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        if(ROWS == 0) return matrix;
        int COLS = matrix[0].size();
        queue<pair<int,int>> pendingNodes;
        vector<vector<int>> dist(ROWS,vector<int>(COLS,INT_MAX));
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(matrix[i][j]==0){
                    dist[i][j] =0 ;
                    pendingNodes.push({i,j});
                }
            }
        }
        vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pendingNodes.empty()){
            pair<int,int> front = pendingNodes.front();
            pendingNodes.pop();
            int row = front.first;
            int col = front.second;
            for(auto &dir:direction){
                int i = row+dir.first;
                int j = col+dir.second;
                if(i>=0 && j>=0 && i<ROWS && j<COLS){
                    if(dist[i][j]>dist[row][col]+1){
                        dist[i][j] =dist[row][col]+1;
                        pendingNodes.push({i,j});
                    }    
                }
            }
        }
        return dist;
    }
};
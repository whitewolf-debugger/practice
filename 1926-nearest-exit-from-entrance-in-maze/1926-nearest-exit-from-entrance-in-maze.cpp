class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>> pendingNodes;
        seen[entrance[0]][entrance[1]]=true;
        pendingNodes.push({entrance[0],entrance[1],0});
        while(!pendingNodes.empty()){
            vector<int> front = pendingNodes.front();
            pendingNodes.pop();
            int row = front[0];
            int col = front[1];
            int dist = front[2];
            if(row == 0 || col ==0 || row == m-1 || col ==n-1){
               if(row==entrance[0] && col==entrance[1]){ }
               else return dist;
            }
            for(auto& dir:directions){
                int i = row+dir.first;
                int j = col+dir.second;
                if(i>=0 && j>=0 && i<m && j<n && !seen[i][j] && maze[i][j]=='.'){
                    pendingNodes.push({i,j,dist+1});
                    seen[i][j]=true;
                }
            }
        }
        return -1;
    }
};
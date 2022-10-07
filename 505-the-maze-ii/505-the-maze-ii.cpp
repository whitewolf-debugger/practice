class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int ROWS = maze.size();
        int COLS = maze[0].size();
        vector<vector<int>> distance(ROWS,vector<int>(COLS,INT_MAX));
        distance[start[0]][start[1]] = 0;
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto &direction : directions){
                int count  =0;
                int i = x + direction.first;
                int j = y + direction.second;
                while(i >= 0 && j >= 0 && i < ROWS && j < COLS && maze[i][j] == 0){
                    i += direction.first;
                    j += direction.second;
                    count++;
                }
                int prevX =  i - direction.first;
                int prevY = j - direction.second;
                if(distance[prevX][prevY] > distance[x][y] + count){
                    distance[prevX][prevY]  = distance[x][y] + count;
                    q.push({prevX,prevY});
                }
                
            }
        }
        int ans = distance[destination[0]][destination[1]];
        return ans == INT_MAX?-1 : ans;
    }
};
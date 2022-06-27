class Solution {
public:
    //question same as number of islands 
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //helps to keep track of visited array
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        //helps to traverse all the directions 
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        // it is final ans
        int ans =0;
        //visiting every block
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //checking whether 1 is there in in that i j and check whether we have seen that 
                if(grid[i][j]==1 && !seen[i][j]){
                    //count = 0
                    int count = 0;
                    //doing dfs using queue 
                    queue<pair<int,int>> pendingNodes;
                    //pushing that row col in queue
                    int row = i;
                    int col = j;
                    pendingNodes.push({row,col});
                    //mark that index as seen 
                    seen[i][j] = true;
                    while(!pendingNodes.empty()){
                        pair<int,int> p = pendingNodes.front();
                        int r = p.first;
                        int c = p.second;
                        pendingNodes.pop();
                        //increase count as we visit ever node connected to current node and it has 1 
                        count++;
                        //checking all the direction arround that block {{0,1},{1,0},{-1,0},{0,-1}}
                        for(pair<int,int> &d:dir){
                            int row = r + d.first;
                            int col = c + d.second;
                            // the direction which we are checking for is in limit  and 1 is placed there and we have not visited that 
                            if(row>=0 && col>=0 && row<m && col<n && !seen[row][col] && grid[row][col]==1){
                                // push that row col in queue where we found 1 (for dfs)
                                pendingNodes.push({row,col});
                                //mark that index as seen 
                                seen[row][col]=true;
                            }
                        }
                    }
                    //update the max size 
                    ans = max(ans,count);
                }
            }
        }
        //return the final ans 
        return ans;
    }
};
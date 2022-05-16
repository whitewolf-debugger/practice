class Solution {
public:
    /*
       8 moves, if you are at i,j
   
	   i-1,j-1    i-1,j    i-1,j+1
	   i,j-1      i,j      i,j+1
 	   i+1,j+1    i+1,j    i+1,j+1
    */
    
    // just check that current i or j inside the boundary and also check it is not having value eqaul to zero
    // and also check it is not visited previously
    bool check(int i,int j,map<pair<int,int>,bool>& visited,vector<vector<int>>& grid)
    {
        int n = grid.size();
    
        // if current i and j follows the given conditions then return true
        if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] != 1 && (visited.find({i,j}) == visited.end()))
        {
            return true;
        }
        
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        // if first element of our grid is not zero then return -1
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
       
        // craeting a queue that will store the cordinates and their corresponding path value
        queue<vector<int>> Q;
        Q.push({0,0,0}); // i,j,dist
        
        // this map will take care of ecah cell that it is vidites or not
        // initially all the cells are false means not visited
        map<pair<int,int>,bool> visited;
        
        // making very first cell is true because we are going to start from here
        visited[{0,0}] = true;
        
        // BFS
        while(!Q.empty())
        {
            // take our the front vector from queue
            auto curr = Q.front();
            Q.pop();
            
            // extracting the data information
            int i = curr[0],j = curr[1],dist = curr[2];
            
            // if we reach to the last cell then return the dist+1 because we will also consider current cell value as 1
            if(i == n-1 && j == n-1)
            {
                return dist+1;
            }
            
            // left(check it will be following or not)
            if(check(i,j-1,visited,grid))
            {
                visited[{i,j-1}] = true;
                Q.push({i,j-1,dist+1});
            }
            
            // right
            if(check(i,j+1,visited,grid))
            {
                visited[{i,j+1}] = true;
                Q.push({i,j+1,dist+1});
            }
            
            // up 
            if(check(i-1,j,visited,grid))
            {
                visited[{i-1,j}] = true;
                Q.push({i-1,j,dist+1});
            }
            
            // down 
            if(check(i+1,j,visited,grid))
            {
                visited[{i+1,j}] = true;
                Q.push({i+1,j,dist+1});
            }
            
            // leftUp
            if(check(i-1,j-1,visited,grid))
            {
                visited[{i-1,j-1}] = true;
                Q.push({i-1,j-1,dist+1});
            }
            
            // rightUp 
            if(check(i-1,j+1,visited,grid))
            {
                visited[{i-1,j+1}] = true;
                Q.push({i-1,j+1,dist+1});
            }
            
            // leftDown 
            if(check(i+1,j-1,visited,grid))
            {
                visited[{i+1,j-1}] = true;
                Q.push({i+1,j-1,dist+1});
            }
            
            // rightDown 
            if(check(i+1,j+1,visited,grid))
            {
                visited[{i+1,j+1}] = true;
                Q.push({i+1,j+1,dist+1});
            }
        }
        return -1;
    }
};
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Use directions to check all the directions 
vector<pair<int , int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
//IS OUT OF BOUNDS check whether the row col pair is within the size of the graph
bool isOOBS(int r, int c, int ROWS, int COLS) {
    if(r < 0 || r >= ROWS) return true;
    if(c < 0 || c >= COLS) return true;
    return false;
}
class Solution{
public:
    vector<vector<int>> chefAndWells(int ROWS,int COLS,vector<vector<char>> &graph){
        // ans stores the ans intially filled with -1,s 
        vector<vector<int>> ans(ROWS,vector<int>(COLS,-1));
        //visited keeps track of visited indexes 
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS , false));
        //queue of {row, column} , distance 
        queue<pair<pair<int , int>, int>> Q;
        for(int r = 0 ; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(graph[r][c] == 'W') {
                    //if at {r,c} there is W then place 0 at the position of well
                    ans[r][c] = 0;
                    //push the well into the queue {{row of well , col of well}, distance }
                    Q.push({{r,c},0});
                    visited[r][c] = true;
                    
                } else if(graph[r][c] == 'N' || graph[r][c] == '.') {
                    //if at that position it is N or . then place 0 in ans array at that posn
                    ans[r][c] = 0;
                } 
            }
        }
        while(!Q.empty()) {
            //get top of the queue 
            auto curr = Q.front();
            // get row , col and distance  of current well and do BFS 
            int r = curr.first.first;
            int c = curr.first.second;
            int d = curr.second;
            Q.pop();
            //searching in all directions and checing all directions 
            for(auto &dir: directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                //if that is not out of bounds and unvisited 
                if(!isOOBS(nr,nc,ROWS,COLS) && !visited[nr][nc]){
                    //if there is a house then visit it and update its distance 
                    //push it in queue with new distance 
                    // if empty space then visit it and push it in with new distance 
                    if(graph[nr][nc] == 'H' && ans[nr][nc] == -1) {
                        //we are doing distance + 2 and not 1 
                        //as we are assuming that we go from home to village and then back 
                        ans[nr][nc] = (d + 2);
                        visited[nr][nc] = true;
                        Q.push({{nr,nc},(d + 2)});
                    } else if(graph[nr][nc] == '.') {
                        Q.push({{nr,nc},(d + 2)});
                        visited[nr][nc] = true;
                    }
                }
            }
        }
        //return ans 
        return ans;
    }
};
/*


H - Represents a house
W - Represents a well
. - Represents an open ground
N - Prohibited area(Not allowed to enter this area)

*/

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
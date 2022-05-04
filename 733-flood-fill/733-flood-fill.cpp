class Solution {
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>>& image,int newColor,int m,int n,int oldColor){
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(vis[i][j] || image[i][j]!=oldColor) return;
        vis[i][j]=1;
        image[i][j]=newColor;           
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(vector<int> x : directions){
            dfs((i+x[0]),(j+x[1]),vis,image,newColor,m,n,oldColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int>> vis(x,vector<int>(y,0));
        int oldColor = image[sr][sc];
        dfs(sr,sc,vis,image,newColor,x,y,oldColor);
        return image;
        
    }
};
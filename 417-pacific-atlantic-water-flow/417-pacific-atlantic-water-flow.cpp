class Solution {
public:
    void dfs(vector<vector<int>> &heights,vector<vector<int>>& ocean,int prev,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || ocean[i][j]==1) return;
        if(prev>heights[i][j]) return;
        ocean[i][j]=1;
        dfs(heights,ocean,heights[i][j],i+1,j,m,n);
        dfs(heights,ocean,heights[i][j],i-1,j,m,n);
        dfs(heights,ocean,heights[i][j],i,j+1,m,n);
        dfs(heights,ocean,heights[i][j],i,j-1,m,n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        if(heights.size()<0) return ans;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> toPacific(m,vector<int>(n,0));
        vector<vector<int>> toAtlantic(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            //first row call for pacific
            dfs(heights,toPacific,INT_MIN,0,i,m,n);
            //last row call for atlantic 
            dfs(heights,toAtlantic,INT_MIN,m-1,i,m,n);
        }
        for(int i=0;i<m;i++){
             //first column call for pacific
            dfs(heights,toPacific,INT_MIN,i,0,m,n);
            //last column call for atlantic 
            dfs(heights,toAtlantic,INT_MIN,i,n-1,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(toPacific[i][j]==1 && toAtlantic[i][j]==1){
                    vector<int> v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};
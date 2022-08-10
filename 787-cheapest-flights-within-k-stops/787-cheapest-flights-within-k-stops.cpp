class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n,1e7);
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++) {
            
            vector<int> temp = dist;
            
            for(auto & edge : flights){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                temp[v] = min(dist[u]+wt,temp[v]);
                    
            }
            dist = temp;
            
        }
        
        if(dist[dst]==1e7) return -1;
        return dist[dst];
    }
};
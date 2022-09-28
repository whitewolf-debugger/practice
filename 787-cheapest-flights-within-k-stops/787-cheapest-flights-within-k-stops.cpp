class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++) {
            
            vector<int> temp = dist;
            
            for(auto & edge : flights){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u] != INT_MAX)
                    temp[v] = min(dist[u]+wt,temp[v]);
                    
            }
            dist = temp;
            
        }
        
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
/*

use bellmanfords algo

1. create an array of distance store 0 at source index and 1e7(INT_MAX) at the remaining position
2. relax all the edges k times 

relaxing edge -:(u,v)
 if(dist[v] > dist[u] + wt){
    dist[v] = dist[u] + wt
}



*/
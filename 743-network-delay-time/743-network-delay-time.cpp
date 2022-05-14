class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
            
        }
        vector<int>vis(n+1,0);
        vector<int>parent(n+1,-1);
        vector<int>dist(n+1,INT_MAX);
        parent[k]=k;
        dist[k]=0;
        vis[k]=1;
        for(int i=0;i<graph[k].size();i++){
            pq.push({graph[k][i].second,graph[k][i].first});
            if(dist[k]+graph[k][i].second<dist[graph[k][i].first]){
                  dist[graph[k][i].first]=  dist[k]+graph[k][i].second;
                    parent[graph[k][i].first]=k;
                }
        }
        
        while(pq.empty()!=true){
           pair<int, int> cur=pq.top();
    pq.pop();
            // cout<<cur.second<<cur.first<<endl;
           if(vis[cur.second ]==0){
           
            for(int i=0;i<graph[cur.second].size();i++){
                // cout<<graph[cur.second][i].first<<endl;
                  if(vis[graph[cur.second][i].first]==0){
                if(dist[cur.second]+graph[cur.second][i].second<dist[graph[cur.second][i].first]){
                  dist[graph[cur.second][i].first]=  dist[cur.second]+graph[cur.second][i].second;
 pq.push({  dist[graph[cur.second][i].first],graph[cur.second][i].first});
                    parent[graph[cur.second][i].first]=cur.second;
                      }
                }
            }
            }
            vis[cur.second]=1;
        }
        int m=INT_MIN;
        for(int i=1;i<dist.size();i++){
            // cout<<dist[i]<<" ";
            if(m<dist[i]){
                m=dist[i];
            }
        }
        if(m!=INT_MAX){
            return m;
        }
        else{
            return -1;
        }
    }
};
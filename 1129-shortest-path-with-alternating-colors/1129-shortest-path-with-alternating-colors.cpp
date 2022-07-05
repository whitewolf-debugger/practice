class Solution {
public:
    //store the node with the edge color and present it as linked list form
    //for visited node store the pair {node, color}.
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
		//create graph representation
        for(auto r: redEdges){
            g[r[0]].push_back({r[1], 0}); //0 means red
        }
        for(auto b: blueEdges){
            g[b[0]].push_back({b[1], 1}); //1 means blue
        }
        //bfs with once start with 0(red color) and once start with 1(blue color)
        vector<int> ans(n, INT_MAX);
        queue<pair<int, int>> q;
        ans[0] = 0;
        for(int k = 0; k < 2; ++k){
            set<pair<int, int>> vis;
        
            q.push({0,k});
            vis.insert({0,k});
            int level = 0;
            while(!q.empty()){
                int n = q.size();
                level++;
                while(n--){
                    int i = q.front().first;
                    int prev = q.front().second;
                    q.pop();
                    for(int j = 0; j < g[i].size(); ++j){
                        if(vis.find(g[i][j]) == vis.end() && g[i][j].second != prev){
                            vis.insert(g[i][j]);
                            q.push(g[i][j]);
                            ans[g[i][j].first] = min(ans[g[i][j].first], level);
                        }
                    }

                }
            }
        }
        for(auto &e: ans){
            if(e == INT_MAX){
                e = -1;
            }
        }
        
        
        return ans;
        
    }
};

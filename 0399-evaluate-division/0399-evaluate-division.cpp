class Solution {
public:
    double bfs(unordered_map<string,vector<pair<string, double>>> &adj, vector<double>& values, vector<vector<string>>& queries, string start,string target) {
        if(adj.find(start) == adj.end()) return -1;
        queue<pair<string, double>> q;
        q.push({start , 1});
        double ans = -1;
        unordered_map<string , bool> visited;
        visited[start] = true;
        while(!q.empty()) {
            auto[curr, dist] = q.front();
            q.pop();
            visited[curr] = true;
            if(curr == target) {
                return dist;
            }
            for(auto &nbr : adj[curr]) {
                string dest = nbr.first;
                double destdist = nbr.second;
                if(visited[dest] == false){
                    q.push({dest,dist * destdist});
                }
            }
        }
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = queries.size();
        vector<double> ans(n,-1);
        unordered_map<string,vector<pair<string, double>>> adj;

        //create adj of u : {v,w}
        // a to b = val then b to a = 1 / val

        for(int i = 0 ; i < values.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        //traverse in queries do bfs
        for(int i = 0 ; i < n; i++) {
            string start = queries[i][0];
            string target = queries[i][1];
            ans[i] = bfs(adj, values,queries,start,target);
        }
        return ans;
    }
};
/*

here we make a map such that distance a to b represents a/b  i.e val[i] 
and we ourselves make reverse edge for each node like in b/a  with weight of edge = 1/val[i]
do bfs for every query keeping track of visited nodes if we are able to visit the target where 
query[i][0] is start and query[i][1] is target for i th query then we return the distance else -1 for that query
now travelling from  a to b cost is currval i.e 1(intially) = 1 x weight of edge b/w(a to b)
and now b to c = 1 x weight of edge b/w(a to b) x weight of edge b/w(b to c) = (result for(a/c)) a = start and c = target 







*/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        vector<set<int>> list(n);
        for(auto & edge :edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i =0 ; i < n;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto &nbr : adj[top]){
                for(auto &parentcurr : list[top]){
                    list[nbr].insert(parentcurr);
                }
                list[nbr].insert(top);
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        for(int i =0 ; i < n;i++) {
            ans[i] = vector<int>(list[i].begin(),list[i].end());
        }
        return ans;
    }
};
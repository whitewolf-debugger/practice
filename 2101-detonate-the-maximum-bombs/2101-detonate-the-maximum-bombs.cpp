class Solution {
public:
    //do DFS 
    void search(vector<vector<int>> & adj,vector<bool> &visited,int sv) {
        visited[sv] = true;
        for(auto & neighbor: adj[sv]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                search(adj,visited,neighbor);
            }
        }
    }
    int dfs(vector<vector<int>> & adj, int n) {
        int ans = 0;
        //we do dfs for every bomb to get maximum chain explosion 
        for(int i = 0 ; i < n;i++) {
            vector<bool> visited(n,false);
            int count = 0;
            search(adj,visited,i);
            for(int i = 0; i < visited.size();i++) {
                if(visited[i]) {
                    count++;
                }
            }
            ans = max(ans,count);

        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i =0 ; i < n; i++) {
            vector<int> b1  = bombs[i];
            for(int j = i + 1 ; j < n;j++) {
                vector<int> b2  = bombs[j];
                //if another bomb gets exploded due to the current bomb so current bomb becomes parent 
                long long distance = pow((b2[0] - b1[0]),2) + pow((b2[1] - b1[1]),2);
                if(distance <= pow(b1[2],2)) {
                    adj[i].push_back(j);
                } 
                if(distance <= pow(b2[2],2)) {
                    adj[j].push_back(i);
                }
            }
        }
        int ans =  dfs(adj,n);
        return ans;
    }
};
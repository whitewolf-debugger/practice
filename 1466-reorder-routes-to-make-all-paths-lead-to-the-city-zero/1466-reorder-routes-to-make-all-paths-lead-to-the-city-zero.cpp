class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        vector<vector<int>> pointed(n);
        for(auto& connection: connections){
            int a= connection[0];
            int b = connection[1];
            edges[a].push_back(b);
            pointed[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n,-1);
        visited[0]=1;
        int reverse =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int front = q.front();
                q.pop();
                for(int i=0;i<edges[front].size();i++){
                    int update = edges[front][i];
                    if(visited[update]==-1){
                        visited[update]=1;
                        q.push(edges[front][i]);
                    }
                }
                for(int i=0;i<pointed[front].size();i++){
                    int update = pointed[front][i];
                    if(visited[update]==-1){
                        visited[update]=1;
                        q.push(pointed[front][i]);
                        reverse++;
                    }
                }
            }
        }
        return n-1-reverse;
    }
};
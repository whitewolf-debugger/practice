class Solution {
public:
    vector<int> kahn(vector<vector<int>> &conditions ,int k){
        vector<int> graph[k+1];
        vector<int> indegree(k+1 , 0);
        vector<int> ans;
        
        for(vector<int> condition : conditions){
            
            //making the graph
            graph[condition[0]].push_back(condition[1]);
            indegree[condition[1]]++;
            
        }
        
        queue<int> q;
        for(int i =1; i <=k; i++){
            
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto& nbr : graph[node]){
                
                indegree[nbr]--;
                
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row_order = kahn(rowConditions , k);
        vector<int> col_order = kahn(colConditions , k);
        
        unordered_map<int,vector<int>> mp;
        
        if(row_order.size() < k || col_order.size() < k){
            return {};
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        
        for(int i = 0; i < k; i++){
            mp[row_order[i]].push_back(i);
        }
        
        for(int i = 0; i < k; i++){
            mp[col_order[i]].push_back(i);
        }
        
        for(auto &coordinates:mp){
            vector<int> coordinate = coordinates.second;
            
            int number = coordinates.first;
            
            int x = coordinate[0];
            int y = coordinate[1];
            
            ans[x][y] = number;
            
        }
        
        return ans;
    }
}; 
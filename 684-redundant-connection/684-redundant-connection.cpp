class Solution {
public:
    int find(vector<int>& parent,int sv){
        if(parent[sv] == sv){
            return sv;
        }
        
        return find(parent,parent[sv]);
    }
    
    void Union(int node1, int node2,vector<int> & parent){
        int Set1 = find(parent,node1);
        int Set2 = find(parent,node2);
        
        if(Set1 != Set2){
            parent[Set2] = Set1;
        }
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;    
        }
        for(auto &edge : edges){
            int SetA = find(parent,edge[0]);
            int SetB = find(parent,edge[1]);
            
            if(SetA != SetB){
                Union(SetA,SetB,parent);
            } else{
                return ans = edge;
            }
        }
        return ans;
    }
};
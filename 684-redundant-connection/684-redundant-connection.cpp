class Solution {
public:
    //find the leader of the given vertex 
    int find(vector<int>& parent,int sv){
        //if the given vertex is parent then it will be parent of itself
        if(parent[sv] == sv){
            return sv;
        }
        
        return find(parent,parent[sv]);
    }
    
    //do the union of both the set 
    void Union(int node1, int node2,vector<int> & parent){
        
        int Set1 = find(parent,node1);
        int Set2 = find(parent,node2);
        
        //do the union , make the leader of the node 2 set the leader of set of node 1
        if(Set1 != Set2){
            parent[Set2] = Set1;
        }
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        //initialy assing every node as parent odf itself
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;    
        }
        
        //traverse in the array of edges 
        for(auto &edge : edges){
            
            //find the parent if both the node
            int SetA = find(parent,edge[0]);
            int SetB = find(parent,edge[1]);
            
            //if the leader if set A and set B are same means that there is a cycle else mege the element of 2 sets 
            if(SetA != SetB){
                Union(SetA,SetB,parent);
            } else{
                
                // if the leader of both the nodes are same then now it is a cycle so store the edge in ans and return it 
                return ans = edge;
            }
        }
        //if there is no edge which has to be removed then ans which has nothing inside it is returned by default 
        return ans;
    }
};
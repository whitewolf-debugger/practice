class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int> &path,int target,unordered_set<int> seen,int node){
        if(node ==target){
            //if we reached the target node ,push the path in ans
            ans.push_back(path);
            // return to break
            return;
        }
        //iterating very linked node with 0th node
        for(auto x : graph[node]){
            //check if we have visited that node to avoid repeatation
            if(seen.find(x)==seen.end()){
                // if we have not visisted that node  then we  insert that node in seen
                seen.insert(x);
                // we push the node in path
                path.push_back(x);
                //discover every path through that node and if we reach the target then it is pushed in ans in base case
                dfs(graph,ans,path,target,seen,x);
                // remove that node from visited so that we discover all path through next node connected to 0
                seen.erase(x);
                // remove that node from path so that we discover all path through next node connected to 0
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;
        vector<int> path;
        //ans stores the ans which is returned 
        vector<vector<int>> ans;
        //is to keep a check at the visited node 
        unordered_set<int> seen;
        //0 is the default through which we have to discover all the path node so we are making it as seen and inserting in path
        seen.insert(0);
        path.push_back(0);
        //calling dfs 
        dfs(graph,ans,path,target,seen,0);
        return ans;
    }
};
/*
    example -: 
    
    [ [1,2] , [3] , [3] , [] ]
       0th    1st   2nd   3rd
       
      so 0th node is connected to 1 and 2 
      1 is connected to 3
      2 is connected to 3 
      and 3 is the target node pointed by every node
      
      so we need to discover all path from 0th node to 3rd node


*/
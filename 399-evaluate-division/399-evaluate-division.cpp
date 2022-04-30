class Solution {
    double dfs(string a,string b,unordered_map<string,unordered_map<string,double>>&mp,unordered_set<string> &visited){
        if(mp[a].find(b) != mp[a].end()){
            return mp[a][b];
        }
        for(auto node : mp[a]){
            if(visited.find(node.first)==visited.end()){
                visited.insert(node.first);
                double val = dfs(node.first,b,mp,visited);
                if(val){
                    mp[a][b]=node.second*val;
                    return mp[a][b];
                }
            }
        }
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,unordered_map<string,double>> mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]][equations[i][1]]=values[i];
            mp[equations[i][1]][equations[i][0]]=(double)1/(values[i]);
        }
        for(int i=0;i<queries.size();i++){
            unordered_set<string> visited;
            double val = dfs(queries[i][0],queries[i][1],mp,visited);
            if(!val){
                ans.push_back(-1.0);
            }
            else{
                ans.push_back(val);
            }
        }
        return ans;
    }
};
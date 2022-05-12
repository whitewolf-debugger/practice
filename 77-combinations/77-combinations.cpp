class Solution {
public:
    bool isValidPath(vector<int>& path){
        for(int i=0;i<path.size()-1;i++){
            if(path[i]>path[i+1]) return false;
        }
        return true;
    }
    void dfs(int k,int n,vector<int> &path,vector<vector<int>>& ans,unordered_set<int>& seen,int start){
        if(path.size()==k){
            if(!isValidPath(path)) return;
            ans.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            if(seen.find(i)==seen.end()){
                path.push_back(i);
                seen.insert(i);
                dfs(k,n,path,ans,seen,i+1);
                path.pop_back();
                seen.erase(i);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        unordered_set<int> seen;
        vector<int> path;
        int start =1;
        if(n==k){
            for(int i=1;i<=n;i++){
                path.push_back(i);
            }
            ans.push_back(path);
            return ans;
        }
        dfs(k,n,path,ans,seen,start);
        return ans;
    }
};
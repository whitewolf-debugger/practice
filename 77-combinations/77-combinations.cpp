class Solution {
public:
    void dfs(int k,int n,vector<int> &path,vector<vector<int>>& ans,unordered_set<int>& seen,int start){
        // if pathsize is = k then we push path in ans vector and terminate with return 
        if(path.size()==k){
            //push path in ans since path has total number of k elements
            ans.push_back(path);
            return;
        }
        //so we send all the numbers to get pairs
        for(int i=start;i<=n;i++){
            //if its not seen then we push it in path
            if(seen.find(i)==seen.end()){
                // we push that unseen number in path
                path.push_back(i);
                //if we have not seen it we see this element by inserting in seen set
                seen.insert(i);
                // do dfs
                dfs(k,n,path,ans,seen,i+1);
                //backtracking
                // after discovering the path we remove this element and discover path with other element
                path.pop_back();
                // we erase that element from seen set
                seen.erase(i);
            }
        }
    }
    vector<vector<int>> combine(int n, int k){
        // ans stores ans
        vector<vector<int>> ans;
        //stores that element which has been visited by us
        unordered_set<int> seen;
        //stores the pairs
        vector<int> path;
        //start index is 1
        int start =1;
        // do dfs 
        dfs(k,n,path,ans,seen,start);
        //ans has answer
        return ans;
    }
};
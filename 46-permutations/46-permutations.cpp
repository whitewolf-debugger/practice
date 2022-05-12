class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>> &ans,vector<int>& path,unordered_set<int> &seen){
        if(nums.size()==path.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(seen.find(i)==seen.end()){
                seen.insert(i);
                path.push_back(nums[i]);
                dfs(nums,ans,path,seen);
                path.pop_back();
                seen.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> seen;
        unordered_set<string> unique;
        dfs(nums,ans,path,seen);
        return ans;
    }
};
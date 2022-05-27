class Solution {
public:
    void dfs(vector<int> &nums,vector<int>& path,vector<vector<int>>& ans,int ind){
        ans.push_back(path);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums,path,ans,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums,path,ans,0);
        return ans;
    }
};
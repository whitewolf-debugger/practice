class Solution {
public:
    void dfs(vector<int> &nums,vector<int>& path,vector<vector<int>>& ans,int ind){
        ans.push_back(path); 
        for(int i=ind;i<nums.size();i++){
            //checking for dublicates 
            if(i>ind && nums[i]==nums[i-1]) continue;
            //backtracking with the forward elements after pushing the current element
            path.push_back(nums[i]);
            dfs(nums,path,ans,i+1);
            //removing the current element to discover different paths 
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //ans is passed by reference so it stores the final ans
        vector<vector<int>> ans;
        // path stores the path , used for dfs 
        vector<int> path;
        dfs(nums,path,ans,0);
        return ans;
    }
};
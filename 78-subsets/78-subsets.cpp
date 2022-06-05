class Solution {
public:
    void backtrack(vector<int> nums,vector<vector<int>> &ans,vector<int> path,int index){       
        if(index == nums.size()){
            ans.push_back(path);
            return;    
        }
        path.push_back(nums[index]);
        backtrack(nums,ans,path,index+1);
        path.pop_back();
        backtrack(nums,ans,path,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums,ans,path,0);
        return ans;
    }
};
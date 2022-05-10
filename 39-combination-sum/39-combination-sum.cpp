class Solution {
public:
    vector<vector<int>> ans; 
    void solve(int i, vector<int>& arr, vector<int>& path, int target,int n)
    {
        if(target == 0) 
        {
            ans.push_back(path); 
            return; 
        }
        
        if(target < 0)
            return;
        
        if(i == n)
            return;
        
        solve(i + 1, arr, path, target,n);
        
        path.push_back(arr[i]);
        solve(i, arr, path, target - arr[i],n); 
        path.pop_back(); 
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear(); 
        int size = arr.size();
        vector<int> path;    

        solve(0, arr, path, target,size);   
        return ans;
    }
};
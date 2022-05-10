class Solution {
public:
    vector<vector<int>> ans; 
    void solve(int i, vector<int>& arr, vector<int>& path, int target,int n)
    {
        if(target == 0){
            ans.push_back(path); 
            return; 
        }
        if(target < 0 || i==n) return;
        if(target>0 && i<n){
            path.push_back(arr[i]);
            solve(i, arr, path, target - arr[i],n); 
            path.pop_back(); 
        }
        solve(i + 1, arr, path, target,n);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int size = arr.size();
        vector<int> path;   
        solve(0, arr, path, target,size);   
        return ans;
    }
};
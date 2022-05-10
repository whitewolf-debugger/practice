class Solution {
public:
    vector<vector<int>> ans; 
    void solve(int i, vector<int>& arr, vector<int>& path, int target,int n)
    {
        // if target == 0 means we got the sequence we push the path in ans
        if(target == 0){
            ans.push_back(path); 
            return; 
        }
        // if target exceeds 0 or iterator i crosses last index we return
        if(target < 0 || i==n) return;
        // else we take it 
        if(target>0 && i<n){
            //take it if we get target = 0 usig it , it is pushed in ans vector
            path.push_back(arr[i]);
            solve(i, arr, path, target - arr[i],n);
            // remove the chosen
            path.pop_back(); 
        }
        // we donot take it 
        solve(i + 1, arr, path, target,n);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        // size stores size of candidates array
        int size = arr.size();
        //stores the path sice we are doing backtracking 
        vector<int> path;   
        // doing dfs using solve function
        solve(0, arr, path, target,size);   
        //ans vector has the ans so we return the ans vector
        return ans;
    }
};
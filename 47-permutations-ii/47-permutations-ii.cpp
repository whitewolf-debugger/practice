class Solution {
public:
    string makeKey(vector<int> &path){
        string str ="";
        for(auto x: path){
            str+=to_string(x)+":";
        }
        return str;
    }
    void bt(vector<int>& nums,unordered_set<int> &seen,vector<int> &path,vector<vector<int>> &ans,unordered_set<string> &uniques){
        if(path.size()==nums.size()){
            string key = makeKey(path);
            if(uniques.find(key)!=uniques.end()) return;
            uniques.insert(key);
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(seen.find(i)==seen.end()){
                seen.insert(i);
                path.push_back(nums[i]);
                bt(nums,seen,path,ans,uniques);
                seen.erase(i);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<string> uniques;
        unordered_set<int> seen;
        bt(nums,seen,path,ans,uniques);
        return ans;
    }
};
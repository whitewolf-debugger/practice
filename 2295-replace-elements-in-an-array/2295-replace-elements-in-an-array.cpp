class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]] = i+1;
            m2[i+1]= nums[i];
        }
        for(int i=0;i<operations.size();i++){
            vector<int> x = operations[i];
            m2[m1[x[0]]] = x[1];
            m1[x[1]] = m1[x[0]];
            m1[x[0]]=0;
        }
        vector<int> ans(nums.size());
        for(int i =0;i<nums.size();i++){
            ans[i]=m2[i+1];
        }
        return ans;
    }
};
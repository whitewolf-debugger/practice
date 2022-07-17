class Solution {
public:
    int Digsum(int num){
        int ans =0;
        while(num>0){
            int rem = num%10;
            ans+=rem;
            num = num/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> pairs;
        int ans =-1;
        unordered_map<int,vector<int>> mp;
        vector<int> digsum(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            digsum[i]=Digsum(nums[i]);
            mp[digsum[i]].push_back(nums[i]);
        }
        for(auto& x:mp){
            vector<int> elements  = x.second;
            sort(elements.rbegin(),elements.rend());
            if(elements.size()<2) continue;
            int sum  = elements[0]+elements[1];
            ans = max(ans,sum);
        }
        return ans;
    }
};
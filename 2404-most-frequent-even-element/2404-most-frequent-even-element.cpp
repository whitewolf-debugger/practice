class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int , int> mp;
        int ans = -1;
        int mx = INT_MIN;
        for(int i =0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto& x: mp){
            if(x.first %2 ==0){
                if(mx < x.second){
                    mx = x.second;
                    ans = x.first;
                }
                else if (mx == x.second){
                    ans = min(ans,x.first);
                }
            }
           
        }
        return ans;
    }
};
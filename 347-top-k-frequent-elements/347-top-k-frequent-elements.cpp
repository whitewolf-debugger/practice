class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> output;
        vector<int> sol;
        pair<int,int> v;
        int size = nums.size();
        for(int i: nums){
            mp[i]++;
        }
        for(auto i : mp){
            v.first = i.second;
            v.second = i.first;
            output.push(v);
            if(output.size()>k){
                output.pop();
            }
        }
        for(int i=0;i<k;i++){
            pair<int,int> p = output.top();
            output.pop();
            sol.push_back(p.second);
        }
        return sol;
    }
};
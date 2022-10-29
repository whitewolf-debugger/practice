class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> time;
        for(int i =0 ; i < plantTime.size();i++) {
            time.push_back({growTime[i],plantTime[i]});
        }
        sort(time.rbegin(),time.rend());
        int ans  = 0;
        int startTime = 0;
        for(auto& times: time) {
            startTime = startTime + times.second;
            ans = max(ans,startTime + times.first);
        }
        return ans;
    }
};
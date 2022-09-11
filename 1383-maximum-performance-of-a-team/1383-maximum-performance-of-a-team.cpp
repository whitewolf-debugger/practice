class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        long long MOD = 1e9 +7;
        vector<pair<int,int>> candidates;
        
        for(int i =0; i < n;i++){
            candidates.push_back({efficiency[i] , speed[i]});
        }
        sort(candidates.rbegin(),candidates.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long runningSpeedSum = 0;
        long long ans = 0;
        for (auto &c: candidates) {
            // put the speed to priority queue
            pq.push(c.second);
            // add to speedSum
            runningSpeedSum  += c.second;
            // we only need to choose at most k engineers so we need to remove a candidate if the queue size is greater than k
            if (pq.size() > k) {
                // remove the smallest speed from the top
                runningSpeedSum  -= pq.top();
                pq.pop();
            }
            // a team is formed now, calculate the performance
            ans = max(ans, runningSpeedSum  * c.first);
        }
        return ans % MOD;
        
    }
};

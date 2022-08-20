class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0;
        int prev = 0;
        int i =0;
        int n = stations.size();
        while(startFuel < target){
            
            while(i < n && startFuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) return -1;
            
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};
/*

    1. When we run out of fuel before reaching the next station, we'll retroactively fuel up: greedily choosing the largest gas stations first.
    
    2.  we drive the largest distance possible before each refueling stop, and therefore have the largest choice of gas stations to (retroactively) stop at.
    
    


*/
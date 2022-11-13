class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> connections(n);
        for(auto & edge: roads) {
           connections[edge[0]]++;
           connections[edge[1]]++;
        }
        long long ans = 0;
        sort(connections.rbegin() , connections.rend());
        for(int i =0 ; i < connections.size();i++) {
            ans += connections[i] * n--;
        }
        return ans;
    }
};
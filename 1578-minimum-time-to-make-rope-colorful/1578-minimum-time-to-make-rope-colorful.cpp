class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i = 0;
        int needed = 0;
        while(i < n) {
            char curr = colors[i];
            int k = i;
            priority_queue<int> pq;
            while(curr == colors[k]) {
                pq.push(neededTime[k]);
                k++;
            }
            needed += pq.top();
            i = k;
        }
        int sum = accumulate(neededTime.begin(),neededTime.end(),0);
        return sum - needed;
    }
};
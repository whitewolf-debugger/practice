class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        for(int i=2;i<=n;i++){
            //create an array which is sum of current element + minimum of last 2 elements and return nth element
            cost[i]=min(cost[i]+cost[i-1],cost[i]+cost[i-2]);
        }
        return cost[n];
    }
};
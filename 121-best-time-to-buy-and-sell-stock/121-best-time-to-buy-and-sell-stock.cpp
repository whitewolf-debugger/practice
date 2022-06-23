class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minVal = INT_MAX;
        for(int i = 0 ;i<prices.size();i++){
                minVal = min(minVal,prices[i]);
                maxprofit = max(maxprofit,prices[i]-minVal);
        }
        return maxprofit;
    }
};
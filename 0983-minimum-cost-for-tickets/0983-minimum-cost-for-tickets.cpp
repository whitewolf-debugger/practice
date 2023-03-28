class Solution {
public:
    int dp(vector<int> &days, vector<int> &costs, int i, int day,vector<vector<int>> &cache) {
        if(i >= days.size()) return 0;
        if(day > 365) return 0;
        if(cache[i][day] != -1) return cache[i][day];
        int one = 0;
        int seven = 0;
        int month = 0;
        //if we fall short of the days then 3 cases are there 
        //take one day pass , 7 day pass or one month pass
        if(days[i] >= day) {
            one = costs[0] + dp(days,costs,i+1,days[i]+1,cache);
            seven = costs[1] + dp(days,costs,i+1,days[i]+7,cache);
            month = costs[2] + dp(days,costs,i+1,days[i]+30,cache);
        } else {
            //if the required day is within the days covered by the pass then 
            one = dp(days,costs,i+1,day,cache);
            seven = dp(days,costs,i+1,day,cache);
            month = dp(days,costs,i+1,day,cache);
        }
        //memoization
        return cache[i][day] =min(one,min(seven,month));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = costs.size();
        vector<vector<int>> cache(366,vector<int>(366,-1));
        return dp(days,costs,0,1,cache);
    }
};
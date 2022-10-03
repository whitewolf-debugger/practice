class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //get the number of colors 
        int n = colors.size();
        //for each color traverse till the color are same and push the time taken to max heap since we will burst baloons with min cost
        int i = 0;
        int needed = 0;
        while(i < n) {
            char curr = colors[i];
            int k = i;
            priority_queue<int> pq;
            //pushing the time in max heap till the color are same 
            while(curr == colors[k]) {
                pq.push(neededTime[k]);
                k++;
            }
            //get the baloon which has max number of time take to explode among same baloons and assume we have exploded the rest small ones
            needed += pq.top();
            i = k;
        }
        //get the total sum of all elements of the time 
        int sum = accumulate(neededTime.begin(),neededTime.end(),0);
        //ans is total time - the required time for baloons which we didnot remove 
        int ans = sum - needed;
        return ans;
    }
};
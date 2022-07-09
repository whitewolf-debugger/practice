class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> score(n);
        for(int i=n-1;i>=0;i--){
            while(!pq.empty() && pq.top().second>i+k){
                pq.pop();
            }
            score[i]=nums[i];
            score[i]+=pq.empty()?0:pq.top().first;
            pq.push({score[i],i});
        }
        return score[0];
    }
};
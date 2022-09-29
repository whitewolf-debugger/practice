class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        int n  = arr.size();
        for(int i = 0; i < k; i++) {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        
        for(int i = k; i < n; i++) {
            if(pq.top().first > abs(arr[i]-x)) {
                pq.pop();
                pq.push({abs(arr[i]-x),arr[i]});
            }
        }
        vector<int> ans;
        
        while(!pq.empty()) {
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //take the default max priority queue 
        priority_queue<pair<int,int>> pq;
        int n  = arr.size();
        //push the k absolute of difference between the 2 numbers in the queue 
        for(int i = 0; i < k; i++) {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        //now from k to n compare 
        for(int i = k; i < n; i++) {
            //top element (element farthest from 2 in queue) is far than the current element 
            if(pq.top().first > abs(arr[i]-x)) {
                //remove the topelement 
                pq.pop();
                //add the current close element to the max heap    
                pq.push({abs(arr[i]-x),arr[i]});
            }
        }
        vector<int> ans;
        
        //take out the k elements and push it in ans vector 
        while(!pq.empty()) {
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        
        //sort the ans in descending order 
        sort(ans.begin(),ans.end());
        //return ans
        return ans;
    }
};
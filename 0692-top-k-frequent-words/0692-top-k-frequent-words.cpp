struct cmp{
    bool operator()(pair<int,string> &a,pair<int,string>& b) {
        if(a.first == b.first) {
            return a.second < b.second ;
        }
        return a.first > b. first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        unordered_map<string,int> mp;
        for(auto & word : words) {
            mp[word] ++;
        }
        for(auto &x : mp) {
            pq.push({x.second,x.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
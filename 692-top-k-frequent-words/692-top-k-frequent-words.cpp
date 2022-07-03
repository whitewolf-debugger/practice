struct cmp{
  bool operator()(pair<int,string>& a,pair<int,string>& b){\
      if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
  }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(int i = 0 ;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto& x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> sol;
        while(!pq.empty()){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};
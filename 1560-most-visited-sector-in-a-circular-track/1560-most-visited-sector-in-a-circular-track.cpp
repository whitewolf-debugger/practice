class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        unordered_map<int,int> freq;
        freq[rounds[0]]++;
        for(int i = 1 ; i< rounds.size();i++){
            int curr = rounds[i-1];
            while(curr!=rounds[i]){
                curr++;
                if(curr>n){ curr=1;
              }
                freq[curr]++;
            }
        }
        vector<int> ans;
        int mx = 0;
        for(auto x: freq){
            if(x.second == mx){
                ans.push_back(x.first);
            }
            else if(x.second>mx){
                mx = x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else continue;
        }
        sort(ans.begin(),ans.end());
        return  ans;
    }
};
class Solution {
public:
    static bool compare(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second?true:false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> p;
        for(int i=0;i<pairs.size();i++){
            p.push_back({pairs[i][0],pairs[i][1]});
        }
        int ans =0;
        sort(p.begin(),p.end(),compare);
        int last = INT_MIN;
        for(auto & pii: p){
            if(last<pii.first){
                last = pii.second;
                ans++;
            }
        }
        return ans;
    }
};
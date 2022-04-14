class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        unordered_map<int,int> loss;
        vector<vector<int>> sol;
        vector<int> first;
        vector<int> second;
        for(int i=0;i<matches.size();i++){
            win[matches[i].at(0)]++;
            loss[matches[i].at(1)]++;
        }
        for(auto x:win){
            if(x.second>0 && loss[x.first]==0){
                first.push_back(x.first);
            }
        }
        for(auto x:loss){
            if(x.second ==1){
                second.push_back(x.first);
            }
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        sol.push_back(first);
        sol.push_back(second);
        return sol;
    }
};
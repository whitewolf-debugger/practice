class Solution {
public:
    static bool compare(vector<int> &a , vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return  a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> lis;
        for(int i = 0;i<envelopes.size();i++){
            int ele = envelopes[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        
        return lis.size();
    }
};
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
        //sort the vector p in order of end limit 
        sort(p.begin(),p.end(),compare);
        //assign last as the end limit but first assign it as the minimum element 
        int last = INT_MIN;
        //iterate through every pair
        for(auto & pii: p){
            // last is upper limit of previous pair if it is lower than the start of current pair means it can be in chain
            if(last<pii.first){
                //assign last as the end limit of the current element
                last = pii.second;
                //increase the size of chain 
                ans++;
            }
        }
        return ans;
    }
};
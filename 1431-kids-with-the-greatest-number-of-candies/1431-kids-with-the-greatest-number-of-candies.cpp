class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        bool check = true;
        for(int i=0;i<candies.size();i++){
            int cal = extraCandies+candies[i];
            for(int j=0;j<candies.size();j++){
                if(i==j){
                    continue;
                }
                if(cal<candies[j]){
                    check = false;
                    break;
                }
                else{
                    check = true;
                }
            }
            ans.push_back(check);
        }
        return ans;
    }
};
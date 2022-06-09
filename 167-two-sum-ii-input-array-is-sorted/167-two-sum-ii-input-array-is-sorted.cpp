class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<vector<int>> solution;
         vector<int>index;
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++){
            mp[numbers[i]]=i+1;
        }
        int diff;
        for(int i=0;i<numbers.size();i++){
            diff = target - numbers[i];
            if(mp[diff]!=0){
                index.push_back(i+1);
                index.push_back(mp[diff]);
                break;
            }
        }
        return index;
    }
};
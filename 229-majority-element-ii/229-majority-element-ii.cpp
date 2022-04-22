class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        for(int i=0;i<nums.size();i++){
            freqMap[nums[i]]++;
        }
        int n = nums.size()/3;
        vector<int> soln;
        for(auto x: freqMap){
            if(x.second>n){
                soln.push_back(x.first);
            }
        }
        return soln;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
        for(int i=0;i<nums.size()-1;i++){
           for(int j=i+1;j<nums.size();j++){
               if((target-nums[i])==nums[j]){
                   v.push_back(i);
                   v.push_back(j);
               }
               if(!v.empty()){
                   break;
               }
           }
        }
        return v;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        vector<int> eve;
        vector<int> odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                eve.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        //concatinating 2 vectors
        eve.insert(eve.end(),odd.begin(),odd.end());
        return eve;
    }
};
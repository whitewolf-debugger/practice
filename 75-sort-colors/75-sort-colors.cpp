class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        int start =0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i =0;i<mp[0];i++){
            nums[start++]=0;
        }
        for(int i =0;i<mp[1];i++){
            nums[start++]=1;
        }
        for(int i =0;i<mp[2];i++){
            nums[start++]=2;
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //creating a map for counting total number of 0 1 and 2 s 
        unordered_map<int,int> mp;
        int start =0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //start helps to keep a check  of index and placing that much number of  0s 1s and 2s 
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
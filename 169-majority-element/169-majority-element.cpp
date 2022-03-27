class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len==1){
            return nums[0];
        }
        int mx = 1;
        int ans = -1;
        unordered_map<int,int> mp;
	    for(int i=0;i<len;i++){
            mp[nums[i]]++;
        }
        for(int i =0;i<len;i++){
            if(mp[nums[i]] > mx){   
                mx = mp[nums[i]];
                ans = nums[i];
            }
        }
        if(mx <= (len/2)){
             return -1;
        }
        return ans;
    }
};
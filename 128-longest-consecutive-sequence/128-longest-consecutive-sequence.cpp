class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longeststreak=0;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(int x : nums){
            if(set.find(x-1)==set.end()){
                int currentstreak=0;
                int num=x;
                while(set.find(x)!=set.end()){
                    x+=1;
                    currentstreak+=1;
                }
                longeststreak=max(longeststreak,currentstreak);
            }
        }
        return longeststreak;
    }
};
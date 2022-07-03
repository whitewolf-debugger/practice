class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return 1;
        int inc =1;
        int dec = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc = dec+1;
            }
            else if(nums[i]<nums[i-1]){
                dec = inc+1;
            }
        }
        return max(inc,dec);
    }
};
/*


                1  7  4  9  2  5
    
    inc         1  2  2  4  4  6
    dec         1  1  3  3  5  5
    
    ans = max(inc,dec)



*/
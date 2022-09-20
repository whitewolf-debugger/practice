class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        int m = nums1.size();
        int n = nums2.size();
        int maxLength = 0;
        vector<int> dp(n,0);
        
        for(int i = 0; i < m; i++){
            for(int j =n-1; j >= 0; j--){
                 
                if(nums1[i] == nums2[j]){
                    if(i == 0 || j == 0) dp[j] = 1; 
                    else dp[j] = 1 + dp[j-1];
                    maxLength = max(maxLength,dp[j]);
                }
                else dp[j] = 0;
            }
        }
        return maxLength;
    }
};
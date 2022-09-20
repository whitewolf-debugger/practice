class Solution {
public:
    int dp(vector<int> &nums1,vector<int> &nums2,int i,int j,int &maxLength,vector<vector<int>> &cache){
        //base case whatn i and j pointer are at the end of corresponding arrays
        if(i >= nums1.size() || j >= nums2.size()){
            return 0;
        }
        
        //memoization step 
        if(cache[i][j] != -1) return cache[i][j];
        int length = 0;
        
        //if the current data is same then we add 1 to the previos data and keep track of maximum length
        if(nums1[i] == nums2[j]) {
            length = 1 + dp(nums1,nums2,i+1,j+1,maxLength,cache);
            maxLength = max(maxLength,length);
        }
        
        // if the data at i of nums1 doesnot matches with data at j of nums2 we return length which was 0 
        return cache[i][j] = length;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        int maxLength = 0;
        
        //cache for memoization 
        vector<vector<int>> cache(1001,vector<int>(1001,-1));
        
        //check  repeated subarray of maximum length for every subarray staring form nums1[i] and nums2[j]
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                dp(nums1,nums2,i,j,maxLength,cache);
            }
        }
        //ans is stored in maxLength which was passed by reference
        return maxLength;
    }
};
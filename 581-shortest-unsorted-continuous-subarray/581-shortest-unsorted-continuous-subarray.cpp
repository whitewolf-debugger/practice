class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int badL = 0;
        int badR = 0;
        
        int n = nums.size();
        
        //first number that is not in ascending order
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) {
                badL = i-1;
                break;
            }
        }    
        
        //last number that is not in ascending order
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > nums[i+1]) {
                badR = i+1;
                break;
            }
        }
        
        //find the min and max values within the range of not ascending order
        int mx = INT_MIN;
        int mn = INT_MAX;

        for(int i = badL; i <= badR; i++) {
            mx = max(nums[i], mx);
            mn = min(nums[i], mn);
        }
        
        //already sorted, return 0
        if(badL == badR) return 0;
        
        //size of the subarray answer
        int ans = badR - badL + 1;
        
        int left = badL-1;
        int right = badR+1;
        /* if a number in left is greater than minimum element of array which we have to sort then we need to increase the size         of array which has to be sorted ans++ is done and left++ is done */
        while(left >= 0 && mn < nums[left]) {
            ans++;
            left--;
        }
         /* if a number in right is greater than maximum element of array which we have to sort then we need to increase the               size of array which has to be sorted so ans++ is done and badR++ is done*/
        while(right< n && mx > nums[right]) {
            ans++;
            right++;
        }
        
        return ans;
    }
};
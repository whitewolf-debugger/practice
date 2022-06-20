class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1 && nums[0]==target){
            return 0;
        }
        int start = 0;
        int end  = nums.size()-1;
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
};
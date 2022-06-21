class Solution {
public:
    //doing binary search which is O(log N)
    int binarySearch(vector<int>& nums,int target,int start,int end){
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //L and R are 2 pointers 
        int L =0;
        int R =1;
        //find the index where the is previous number  greater than the next one since that is point of division of 2 sorted arrays 
        while(R<nums.size() && nums[L]<nums[R]){
            L++;
            R++;
        }
        //call binary search on left which is 0 to L
        int Left = binarySearch(nums,target,0,L);
        //call binary search on right which is R to nums.size()-1 (end)
        int Right = binarySearch(nums,target,R,nums.size()-1);
        //if either of left or right is not -1 means we found our target return that target
        if(Left!=-1) return Left;
        if(Right!=-1) return Right;
        //if we didnot find our target we return -1
        return -1;
    }
};
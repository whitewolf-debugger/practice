class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        for(int i =1 ; i < nums.size()-1 ; i++) {
            if(2 * nums[i] == (nums[i-1] + nums[i + 1])) {
                swap(nums[i],nums[i+1]);
            }
        }

        for(int i = nums.size() - 2; i > 0 ; i--) {
            if(2* nums[i] == (nums[i-1] + nums[i + 1])) {
                swap(nums[i], nums[i-1]);
            }
        }
        return nums;
    }
};
/*

    go from the start 
    1st iteration left to right
    we swap ith and i+ 1 th element swap(arr[i] , arr[i+1])
    1   2   3   4   5
        ^

    2 = (1+3) / 2

    so swap 2 and 3 

    1   3   2   4   5
            ^

    2 != (3 + 4) / 2

    1   3   2   4   5
                ^
    4 != (5 + 2) / 2




    2nd iteration right to left

    1   3   2   4   5
                ^
    4 != (5 + 2) / 2

    1   3   2   4   5
            ^
    2 != (3 + 4) / 2


    1   3   2   4   5
        ^
    3 != (1 + 2) / 2
    while traversing from right to left
    if there would have been same then we would have swapped (arr[i],arr[i-1])

*/
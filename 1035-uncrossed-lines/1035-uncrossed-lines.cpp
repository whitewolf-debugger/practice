class Solution {
public:
    // dynamic programming method using memoization
    int dp(vector<int> &nums1,vector<int> &nums2, unordered_map<int, vector<int>> &um, int i, int min_idx,vector<vector<int>> &cache) {
        //if we exceed the nums1 array then return 0
        if(i >= nums1.size()) return 0;
        //memoization step
        if(cache[i][min_idx + 1] != -1) return cache[i][min_idx + 1];
        // for element nums [i] search for upper+_bound 
        //i.e index greater than min index for same element in nums 2
        vector<int> v = um[nums1[i]];
        auto iter = upper_bound(v.begin(),v.end(), min_idx);
        int take = 0, notTake = 0;
        //if upper_bound iterator points to an index which is not the end of the vector 
        //i.e we got the index which is just greater than the min_index
        if(iter != v.end()) {
            //take that line 
            take += 1 + dp(nums1,nums2,um,i + 1,max(*iter, min_idx),cache);
        }
        //case 2 when we leave it for leaving we do need to check any condition
        notTake = dp(nums1,nums2,um,i + 1,min_idx,cache);
        //return max of take and not take 
        return cache[i][min_idx + 1] = max(take, notTake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> um;
        //making map of element in nums 2 and their respective indices where it is present in the vector 
        for(int i = 0 ; i < nums2.size(); i++) {
            um[nums2[i]].push_back(i);
        }
        vector<vector<int>> cache(nums1.size() + 1,vector<int>(nums2.size() + 2, -1));
        int ans = dp(nums1,nums2,um,0,-1,cache);
        return ans;
    }
};

/*


    [2,5,1,2,5]

    0   1   2   3   4
    2   5   1   2   5
    i

    0   1   2   3   4   5
    10  5   2   1   5   2
    j

    min_idx = 2

    
    Steps : 
    1. map we make using nums 2
    
    um: {
        10: [0]
        5:  [1, 4]
        2:  [2, 5]
        1:  [3]
    }

    2. we traverse in nums 1 using i for every 1 
    3. search for map for location of same element grater than minIndex since once we have made a line using that index in the nums 2 then we cannot use any index behind that index because that will lead to line crossing each other so we keep track of min index for nums 2 
    4. take the line we can and add +1 and return max of take and notTake i.e once by take and once by not taking 

*/
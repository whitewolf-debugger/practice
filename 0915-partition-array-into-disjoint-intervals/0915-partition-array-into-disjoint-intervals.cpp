class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>> left;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> right;
        for(int i =0 ; i < n;i++) {
            right.push({nums[i] , i});
        }
        
        for(int i = 0 ; i < n; i++) {
            left.push({nums[i],i});
            while(!right.empty() && right.top().second <= i) {
                right.pop();
            }
            if(left.top().first <= right.top().first) {
                return i+1;
            }
        }
        return -1;
    }
};

/*


Intuition
If the largest element of left part is smaller or equal than the smallestement of right part
then, all the elements of left part are smaller or equal to the elements of the right part.

DS required : 2 priority queues (containing pairs of element and index)

first pq: contains the left part of the array. This pq is of type max_heap (keeping the maximum element at the top)
second pq: contains the right part of the array. min_heap (keeping the min element at top)
Procedure

Initially store all the elements of array in second.
traverse through the array from i to n-1:
Add the ith element to first pq.
Check the top element of second pq if the index of the top element is less than i
then this element belongs to the first part.
Keep popping the array until you get an index that belong to the second part.
If the top element of second pq is greater equal to the top element of first pq,
we've got our answer. return i+1 for the length of the left part .
*/
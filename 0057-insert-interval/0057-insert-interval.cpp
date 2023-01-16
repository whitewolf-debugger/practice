class Solution {
    //checks whether the interval is overlapping
    bool isOverlapping(vector<int> &a, vector<int> &b) {
        return min(a[1],b[1]) - max(a[0],b[0]) >= 0;
    }

    //merges the 2 intervals a and b
    vector<int> mergeIntervals(vector<int> &a, vector<int> &b) {
        return {min(a[0],b[0]) , max(a[1],b[1])};
    }

    ///inserts the current given interval to the next of interval whose start is more than given intervals start
    bool insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        for(int i =0; i < intervals.size(); i++) {
            if(intervals[i][0] > newInterval[0]) {
                //if we get such start which is more than current start we return true after inserting 
                intervals.insert(intervals.begin() + i, newInterval);
                return true;
            }
        }
        //else return false
        return false;
    }

    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        //if we didnot get start more than current start then insert the interval at the end 
        if(!insertInterval(intervals, newInterval)) {
            intervals.push_back(newInterval);
        }
        
        for(int i =0; i < intervals.size(); i++) {
            //get the current interval in the intervals array
            vector<int> curInterval = {intervals[i][0], intervals[i][1]};
            //while there is an overlap merge the intervals 
            while(i < intervals.size() && isOverlapping(curInterval,intervals[i])) {
                curInterval = mergeIntervals(curInterval,intervals[i]);
                i++;
            }
            //since after while i++ is done so we come back 
            i--;
            //insert hte current merged intervals in the ans 
            ans.push_back(curInterval);
        }
        return ans;
        
    }
};
/*

    ___________
        ____________


        ____________
    ___________


*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // solving using binary search 
    int firstBadVersion(int n) {
        //start is first device 
        long int start = 1;
        //end is last device
        long int end = n;
        while(start<=end){
            //find out mid 
            int mid = (start+end)/2;
            //if we find bad device at mid check whether previous device is bad if it is bad then we are not at start
            if(isBadVersion(mid) && mid-1>0 && isBadVersion(mid-1)){
                //so end = mid-1;
                end =mid-1;
            }
            //if we got good device means bad device index is ahead so start = mid+1
            else if(!isBadVersion(mid)){
                start = mid+1;
            }
            else{
                //if we got bad device at mid such that there is no bad device before that means it is start so return mid 
                return mid;
            }
        }
        return -1;
    }
};
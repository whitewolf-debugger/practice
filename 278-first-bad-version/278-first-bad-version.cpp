// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int start = 1;
        long int end = n;
        while(start<=end){
            int mid = (start+end)/2;
            if(isBadVersion(mid) && mid-1>0 && isBadVersion(mid-1)){
                end =mid-1;
            }
            else if(!isBadVersion(mid)){
                start = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
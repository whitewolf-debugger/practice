class Solution {
public:
    bool isValid(vector<int> &piles, int h, int k) {
        if(k <= 0)return false;
        long long needed = 0;
        for(long long x: piles) {
            //since current time if it is less than k then we get 0 if we do k + x - 1/ k we get 1
            long long currtime = (x + k - 1)/ k;
            //add the time needed to eat this banana
            needed += currtime;
            //if time needed to eat banana till now is > h then return false
            if(needed > h) return false;
        }
        //else return true
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long L = 0;
        long long R = INT_MAX;
        
        while(L < R) {
            long long mid = L + (R - L)/2;
            if(isValid(piles,h,mid)) {
                //if we got hour < h for lets suppose k
                //we want minimum k
                //so k - 1 might give time needed z 
                //where z might be such that z > hour and z < h
                //so we put R at mid
                R = mid;
            } else {
                //if it current hour for k is more than h
                //then mid should be increase(bananas-per-hour eating speed)
                //so L + 1 is done 
                L = mid + 1;
            }
        }

        return (int)L;
    }
};
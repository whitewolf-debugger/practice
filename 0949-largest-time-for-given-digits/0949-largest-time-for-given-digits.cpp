class Solution {
public:
    bool isPossible(vector<int> &arr,int hour ,int minutes) {
        vector<int> time(4);
        time[0] = hour/10;
        time[1] = hour % 10;
        time[2] = minutes / 10;
        time[3] = minutes % 10;
        sort(arr.begin(),arr.end());
        sort(time.begin(),time.end());
        return time == arr;     
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string chonk = "";
        for(int hour = 23; hour >=0 && chonk == "";hour--) {
            for(int minutes = 59; minutes >=0 && chonk == "" ; minutes--) {
                if(isPossible(arr,hour,minutes)) {
                    chonk += '0' + (hour/10) ;
                    chonk+= '0' + (hour % 10) ;
                    chonk+= ':' ;
                    chonk+= '0' + (minutes / 10) ;
                    chonk+= '0' + (minutes % 10) ;
                    break;
                }
            }
        }
        return chonk;
    }
};
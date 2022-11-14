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
        string result = "";
        for(int hour = 23; hour >=0 && result == "";hour--) {
            for(int minutes = 59; minutes >=0 && result == "" ; minutes--) {
                if(isPossible(arr,hour,minutes)) {
                    result += '0' + (hour/10) ;
                    result+= '0' + (hour % 10) ;
                    result+= ':' ;
                    result+= '0' + (minutes / 10) ;
                    result+= '0' + (minutes % 10) ;
                    break;
                }
            }
        }
        return result;
    }
};
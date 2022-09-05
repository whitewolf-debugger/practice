bool compare(vector<int> &a,vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),compare);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long,int>>> engaged;
        priority_queue<int,vector<int>,greater<int>> unused;
        unordered_map<int,int> freqMap;
        
        for(int i = 0; i < n;i++){
            unused.push(i);
        }
        
        for(auto meeting: meetings){
            int start = meeting[0];
            int end = meeting[1];
            
            while(engaged.size() > 0 && engaged.top().first <= start){
                int room = engaged.top().second;
                engaged.pop();
                unused.push(room);
            }
            
            if(unused.size() > 0){
                int top = unused.top();
                engaged.push({end,top});
                unused.pop();
                freqMap[top]++;
                
            }else{
                pair<long long , int> topmost = engaged.top();
                engaged.pop();
                freqMap[topmost.second]++;
                
                long long newEnd = topmost.first + (end - start);
                engaged.push({newEnd, topmost.second});
                
            }
        }
        
        int maxi  =0;
        for(int i = 1; i < n; i++){
            if(freqMap[i] > freqMap[maxi]){
                maxi = i;
            }
        }
        
        return maxi;
    }
};
/*


 0 to n-1 
 




*/
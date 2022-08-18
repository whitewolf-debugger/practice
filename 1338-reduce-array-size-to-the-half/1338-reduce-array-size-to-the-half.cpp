class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int target = (n+1)/2;
        unordered_map<int,int> freqMap;
        for(int x : arr){
            freqMap[x]++;
        }
        vector<int> freaks;
        for(auto& [num,count] : freqMap){
            freaks.push_back(count);
        }
        sort(freaks.rbegin(),freaks.rend());
        
        for(int i = 0 ; i < n; i++){
            target -= freaks[i];
            if(target <= 0) return i+1;
        }
        return 0;
    }
};
/*


 [3,3,3,5,5,5,2,2,7]
 
 unordered_map freqMap: {
        3:  4
        5:  3
        2:  2
        4:  1
 }

 priority_queue<pair<int,int>> pq;
 
 pq.push({4 , 3});
 pq.push({3 , 5});
 pq.push({2 , 2});
 pq.push({1 , 7});

    


*/
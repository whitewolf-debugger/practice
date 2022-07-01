class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int trucksize) {
        priority_queue<pair<int,int>> pq;
        int count =0;
        int units =0;
        for(int i=0;i<boxTypes.size();i++){
            vector<int> box = boxTypes[i];
            pq.push({box[1],box[0]});
        }
        while(!pq.empty() && count<trucksize){
            if(count+pq.top().second<trucksize){
                count+=pq.top().second;
                units+=(pq.top().second*pq.top().first);
                pq.pop();
            }else{
                int qty = trucksize - count;
                count+=qty;
                units+= qty*(pq.top().first);
            }
        }
        return units;
    }
};
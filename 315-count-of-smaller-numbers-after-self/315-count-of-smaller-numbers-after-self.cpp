class Solution {
public:
    void merge(vector<pair<int,int>> &v,int start,int end,vector<int>& count){
        int i =start;
        int m = (start+end)/2;
        int j = m+1;
        vector<pair<int,int>> temp;
        while(i<=m && j<=end){
            if(v[i].first<=v[j].first){
                temp.push_back(v[j]);
                j++;
                
            }
            else{
                count[v[i].second]+=end-j+1;
                temp.push_back(v[i]);
                i++;
            }
        }
        while(i<=m){
            temp.push_back(v[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(v[j]);
            j++;
        }
        int k =0;
        for(int idx=start;idx<=end;idx++){
            v[idx]=temp[k++];
        }
    }
    void mergeSort(vector<pair<int,int>> &v,int start,int end,vector<int>& count){
        if(start>=end) return ;
        int mid = (start+end)/2;
        mergeSort(v,start,mid,count);
        mergeSort(v,mid+1,end,count);
        merge(v,start,end,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        vector<int> count(n,0);
        int start =0;
        int end = n-1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        mergeSort(v,start,end,count);
        return count;
    }
};
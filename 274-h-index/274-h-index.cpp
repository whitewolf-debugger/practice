class Solution {
public:
    bool isValid(vector<int>& citations, int M){
        int good =0;
        for(int x : citations){
            if(x>=M) good++;
        }
        return good>=M;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int L = 1;
        int R = n;
        int ans=0;
        while(L<=R){
            int p = L +(R-L)/2;
            if(isValid(citations, p)){
                ans =p;
                L =p+1;
            }else{
                R = p-1;
            }
        }
        return ans;
    }
};
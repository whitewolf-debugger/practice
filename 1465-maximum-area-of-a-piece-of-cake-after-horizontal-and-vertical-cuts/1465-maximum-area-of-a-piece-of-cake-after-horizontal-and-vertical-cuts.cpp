class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int size1 = horizontalCuts.size();
        int size2 = verticalCuts.size();
        int a = 0;
        int b = 0;
        for(int i=0;i<size1-1;i++){
            a = max(a,horizontalCuts[i+1]-horizontalCuts[i])%1000000007;
        }
        for(int j=0;j<size2-1;j++){
            b = max(b,verticalCuts[j+1]-verticalCuts[j])%1000000007;
        }
        
        return (1LL*a*b)%1000000007;
    }
};
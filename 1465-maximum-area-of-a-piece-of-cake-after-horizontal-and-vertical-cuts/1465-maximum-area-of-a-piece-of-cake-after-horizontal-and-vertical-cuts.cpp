class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        //ans is the product between maximunm maximum height difference and maxmimum width distance
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        //we are pushing in the boundaries since they also act as a cut lines 
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        //sort all the cut line 
        int size1 = horizontalCuts.size();
        int size2 = verticalCuts.size();
        int a = 0;
        int b = 0;
        //find out maximum diff b/w 2 consecutive horizontal lines 
        for(int i=0;i<size1-1;i++){
            a = max(a,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        //find out maximum diff b/w 2 consecutive horizontal lines 
        for(int j=0;j<size2-1;j++){
            b = max(b,verticalCuts[j+1]-verticalCuts[j]);
        }
        //convert product to long long and reuturn after doing modulo 
        return (1LL*a*b)%1000000007;
    }
};
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool xOverlap = false;
        bool yOverlap = false;
        if(rec1[0]<=rec2[0] && rec2[0]<rec1[2]){
            xOverlap = true;
        }
        if(rec2[0]<=rec1[0] && rec1[0]<rec2[2]){
            xOverlap = true;
        }
        if(rec1[1]<=rec2[1] && rec2[1]<rec1[3]){
            yOverlap = true;
        }
        if(rec2[1]<=rec1[1] && rec1[1]<rec2[3]){
            yOverlap = true;
        }
        return xOverlap && yOverlap;
    }
};
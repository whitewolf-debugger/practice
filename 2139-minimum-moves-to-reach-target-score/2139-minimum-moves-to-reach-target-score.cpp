class Solution {
public:
    long int moves(int target, int maxDoubles){
        if(target<=1){
            return 0;
        }
        if(maxDoubles==0){
            return target-1;
        }
        if(target%2==0 && maxDoubles>0){
            return 1+moves(target/2,maxDoubles-1);
        }
        else{
            return 1+moves(target-1,maxDoubles);
        }
    }
    int minMoves(int target, int maxDoubles) {
        return moves(target,maxDoubles);
    }
};
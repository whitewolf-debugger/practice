class Solution {
public:
    long int moves(int target, int maxDoubles){
        //if target is less than 1 we return 0
        if(target<=1){
            return 0;
        }
        //basecases if maxDouble is 0 then ans is target-1
        if(maxDoubles==0){
            return target-1;
        }
        if(target%2==0 && maxDoubles>0){
            //if target is divisible by 2 then we use maxDoubles 
            return 1+moves(target/2,maxDoubles-1);
        }
        else{
            //else we just decrese target
            return 1+moves(target-1,maxDoubles);
        }
    }
    int minMoves(int target, int maxDoubles) {
        return moves(target,maxDoubles);
    }
};
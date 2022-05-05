class Solution {
public:
     
    int minMoves(int target, int maxDoubles) {
        int min=0;
        if(target==1)
            return 0;
        
        if(target%2==0 && maxDoubles>=1)
        {
            return 1+minMoves(target/2,maxDoubles-1);
        }
        if(target%2!=0 || maxDoubles>0)
        {
            return 1+minMoves(target-1,maxDoubles);
        }
        if(target%2!=0 || maxDoubles==0) // if we run out of double moves simply return 
										//remaining target -1(we have to reach 1 not zero)  
										//this condition helps to counter recursion stack overflow
        {
            return target-1;
        }        
        return 0;
    }
};

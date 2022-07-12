class Solution {
public:
    bool makesquare(vector<int>& matchsticks,int currIndex,int side1,int side2,int side3,int side4){
        //if we have iterated through the full araay 
        if(currIndex==matchsticks.size()){
            //if each side is zero means we made the square 
            if(side1==0 && side2==0 && side3==0 && side4 ==0){
                return true;
            }
            //else we were not able to make the square 
            else return false;
        }
        //if length of side is more than the current element 
        if(matchsticks[currIndex]<=side1){
            //reduce the current side by the current size 
            side1-=matchsticks[currIndex];
            //if at any point we hit the case where all the sides are 0 return true;
            if(makesquare(matchsticks,currIndex+1,side1,side2,side3,side4)) return true;
            //backtracking step 
            side1+=matchsticks[currIndex];
        }
        //do similar for all sides 
        if(matchsticks[currIndex]<=side2){
             side2-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1,side1,side2,side3,side4)) return true;
            side2+=matchsticks[currIndex];
        }
        if(matchsticks[currIndex]<=side3){
            side3-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1,side1,side2,side3,side4)) return true;
            side3+=matchsticks[currIndex];
        }
        if(matchsticks[currIndex]<=side4){
            side4-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1,side1,side2,side3,side4)) return true;
            side4+=matchsticks[currIndex];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        //if size of the matchsticks is less than 4 means we cannot make 4 sides 
        if(matchsticks.size()<4) return false;
        //sum of all the elements of the array 
        int totalsum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        //if sum of all the element cannot be divided into 4 halves then return false
        if(totalsum%4!=0) return false;
        //calculate the sum for each side the sum sum will be same
        int target = totalsum/4;
        //sort the aray in reverse order 
        sort(matchsticks.rbegin(),matchsticks.rend());
        //call the backtracking make square function  assign side = target and we reduce the target 
        return makesquare(matchsticks,0,target,target,target,target);
        //at the end if all sides are zero means we were able to make 
    }
};
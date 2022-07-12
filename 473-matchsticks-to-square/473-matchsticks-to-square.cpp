class Solution {
public:
    bool makesquare(vector<int>& matchsticks,int currIndex,int side1,int side2,int side3,int side4){
        if(currIndex==matchsticks.size()){
            if(side1==0 && side2==0 && side3==0 && side4 ==0){
                return true;
            }
            else return false;
        }
        if(matchsticks[currIndex]<=side1){
            side1-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1,side1,side2,side3,side4)) return true;
            side1+=matchsticks[currIndex];
        }
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
        int totalsum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(totalsum%4!=0) return false;
        int target = totalsum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        return makesquare(matchsticks,0,target,target,target,target);
    }
};
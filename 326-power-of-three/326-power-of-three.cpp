class Solution {
    bool power(int i,int n){
        if(pow(3,i)>n){
            return false;
        }
        if(pow(3,i)==n){
            return true;
        }
        return power(i+1,n);
    }
public:
    bool isPowerOfThree(int n) {
        return power(0,n);
        
    }
};
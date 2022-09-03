class Solution {
public:
    void dfs(int size,int n,int k,int num,unordered_set<int> &seen,vector<int> &ans){
        //check if the size of the number is  equal to the required size 
        if(size == n){
            
            //if the size is same and the number we got is not a dublicate 
            if(seen.find(num) == seen.end()){
                
                //mark the number as seen by inserting it in the set 
                seen.insert(num);
                
                //push the number back in to the ans 
                ans.push_back(num);
            }
            //base case it is and we dont want any other number in num which we are making so return 
            return;
        }
        
        //extract the last digit
        int LastDigit = num % 10;
        
        // check if we can make the new digit by adding k with last digit which is option 1 
        if((LastDigit + k) < 10){
            
            //do dfs call and our new number is ((current number x 10) + (LastDigit + k)) like (35x10)+2 = 352 the same way 
            dfs(size+1,n,k,((num*10)+(LastDigit + k)),seen,ans);
        }
        
        //check if we can make the new digit by subtracting k with the last digit option 2 
        if((LastDigit - k) >= 0){
            
            //do dfs call and our new number is ((current number x 10) + (LastDigit - k)) like (35x10)+2 = 352 the same way 
            dfs(size+1,n,k,((num*10)+(LastDigit - k)),seen,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        //setting the current size as 1 since using loop we are sending the 1st digit 
        int CurrSize  = 1;
        
        //seen to keep track of dublicates 
        unordered_set<int> seen;
        
        //ans stores the ans 
        vector<int> ans;
        
        //select the first digit from 1 - 9 and use dfs to create rest of the number 
        for(int i = 1; i < 10; i++){
            dfs(CurrSize,n,k,i,seen,ans);
        }
        //since we have passed ans by reference so return the updated ans 
        return ans;
    }
};
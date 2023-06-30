//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    
	    int n = s.size();
	    int sum = 0;
	    //we want to traverse from right to left 
	    reverse(s.begin(),s.end());
	    for(int i = 0 ; i < n; i++) {
	        //if 1 is at even position add 1 
	        // if 1 is at odd position add 2 to the sum 
	        if(s[i] == '1') {
	            if(i % 2 == 0) {
	                sum += 1;
	            } else {
	                sum += 2;
	            }
	        }
	    }
	    return  (sum % 3) == 0;
	}

};
/*
    0   0   0   2   1
    0   0   0   1   1   sum = 3 % 3 = 0                
   
   
    0   2   0   0   1 
    0   1   0   0   1   sum = 3  % 3 =0
    
   

    0   0   0   0   1
    0   0   0   0   1    sum = 1 % 3 != 0
    
  
    


*/

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
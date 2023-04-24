//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);
        stack<int> leftStack, rightStack;
        for(int i = 0 ; i < n; i++) {
            while(!leftStack.empty() && arr[leftStack.top()] >= arr[i]) {
                leftStack.pop();
            }
            left[i] = leftStack.empty() ? -1 : leftStack.top();
            leftStack.push(i);
        }
        for(int i = n-1; i >= 0; i--) {
            while(!rightStack.empty() && arr[rightStack.top()] >= arr[i]) {
                rightStack.pop();
            }
            right[i] = rightStack.empty() ? -1 : rightStack.top();
            rightStack.push(i);
        }
        for(int i =0;i < n; i++) {
            if(left[i] == right[i] && left[i] == -1) {
                ans[i] = -1;
            } else if(left[i] == -1) {
                ans[i] = right[i];
            } else if (right[i] == -1){
                ans[i] = left[i];
            } else {
                
                if(right[i] == -1 && left[i] == -1) {
                       ans[i]= -1; 
                } else if(arr[left[i]] == -1) {
                     ans[i] = right[i];
                }else if(arr[right[i]] == -1){
                    ans[i] = left[i];
                } else {
                    if(abs(i - left[i]) > abs(right[i] - i)) {
                        ans[i] = right[i];
                    } else if(abs(i - left[i]) < abs(right[i] - i)) {
                        ans[i] = left[i];
                    } else {
                        if(arr[left[i]] > arr[right[i]]) {
                            ans[i] = right[i];
                        } 
                        else if(arr[left[i]] < arr[right[i]]) {
                            ans[i] = left[i];
                        } else  {
                            ans[i] = min(left[i], right[i]);
                        }
                    }
                }
            }
        }
        // code here
        return ans;
    }
};


/*
    8
    4 8 6 5 3 8 5 5
    0 1 2 3 4 5 6 7
        ^
    left 
    -1 0 0 0 0 4 4 4
    
    left stack{
 
      4
      0  
    }
    
    
    right
    4 2 3 4 -1 6 -1 -1
    
    right stack {
        
        
        
        4
    }
    

    correct 
    1 3 3 -1 3 6 -1 -1
    
    left
   -1 
    
    my soln
    4 0 

*/

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
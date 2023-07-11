//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int L = 0 , R = m - 1, U = 0, D = n - 1, count = 0, ans = 0,r, c;
 		while(L <= R && U <= D) {
 		    r = U;
 		    for(c = L ; c <= R; c++) {
 		        count++;
 		        if(count == k) {
 		            ans = a[r][c];
 		            break;
 		        }
 		    }
 		    U++;
 		    c = R;
 		    for(r = U; r <= D; r++) {
 		        count++;
 		        if(count == k) {
 		            ans = a[r][c];
 		            break;
 		        }
 		    }
 		    R--;
 		    r = D;
 		    for(c = R; c >= L; c--) {
 		        count++;
 		        if(count == k) {
 		            ans = a[r][c];
 		            break;
 		        }
 		    }
 		    D--;
 		    c = L;
 		    for(r = D; r >= U; r--) {
 		        count++;
 		        if(count == k) {
 		            ans = a[r][c];
 		            break;
 		        }
 		    }
 		    L++;
 		}
 		return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
#include<bits/stdc++.h>
class Solution {
public:
    int num_help(int *arr,int n){
        if(n==1||n==0||n==2||n==3){
            return n;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        int ans = INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+num_help(arr,n-i*i));
        }
        arr[n]=ans;
        return arr[n];
    }
    int numSquares(int n) {
        int *arr = new int[n+1];
        for(int i=0;i<=n;i++){
            arr[i]=-1;
        }
        return num_help(arr,n);
    }
};
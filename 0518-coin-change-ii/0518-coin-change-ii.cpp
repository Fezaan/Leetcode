class Solution {
public:
    int f(int n, int k, vector<int>& arr, vector<vector<int>>& dp){
        if(n==0){
            if(k%arr[n]==0) return 1;
            else    return 0;
        }
        if(dp[n][k]!=-1)    return dp[n][k];
        int np=f(n-1,k,arr,dp);
        int p=0;
        if(arr[n]<=k)   p=f(n,k-arr[n],arr,dp);
        return dp[n][k]=np+p;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
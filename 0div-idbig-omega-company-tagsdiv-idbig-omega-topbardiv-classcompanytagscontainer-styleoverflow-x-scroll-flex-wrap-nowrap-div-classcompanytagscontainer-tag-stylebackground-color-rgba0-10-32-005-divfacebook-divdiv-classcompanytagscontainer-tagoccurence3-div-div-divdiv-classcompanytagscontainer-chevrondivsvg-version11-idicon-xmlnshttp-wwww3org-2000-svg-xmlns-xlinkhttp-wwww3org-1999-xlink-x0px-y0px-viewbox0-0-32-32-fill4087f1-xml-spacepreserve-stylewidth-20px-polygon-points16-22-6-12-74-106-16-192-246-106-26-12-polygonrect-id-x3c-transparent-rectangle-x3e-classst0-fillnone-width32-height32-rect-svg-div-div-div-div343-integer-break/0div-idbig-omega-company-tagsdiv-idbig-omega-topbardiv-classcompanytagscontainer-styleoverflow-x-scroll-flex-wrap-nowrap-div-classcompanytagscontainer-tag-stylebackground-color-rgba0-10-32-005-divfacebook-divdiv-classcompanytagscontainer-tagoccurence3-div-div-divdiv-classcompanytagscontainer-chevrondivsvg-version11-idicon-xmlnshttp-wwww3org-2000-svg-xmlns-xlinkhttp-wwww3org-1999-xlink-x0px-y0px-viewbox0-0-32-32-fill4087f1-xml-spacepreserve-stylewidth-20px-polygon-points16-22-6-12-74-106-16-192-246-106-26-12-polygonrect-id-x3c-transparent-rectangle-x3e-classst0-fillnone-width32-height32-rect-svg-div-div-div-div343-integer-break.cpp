class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n==1)    return 0;
        if(dp[n]!=-1)   return dp[n];
        dp[n]=n;
        for(int i=1;i<n;i++){
            int x= f(i,dp)*f(n-i,dp);
            dp[n]=max(x,dp[n]);
        }
        return dp[n];
    }
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
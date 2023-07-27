class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n==1||n==0)  return 1;
        if(dp[n]!=-1)   return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
        int pev2=1,pev1=1;
        int f;
        for(int i=2;i<=n;i++){
            f=pev1+pev2;
            pev2=pev1;
            pev1=f;
        }
        return pev1;
    }
};
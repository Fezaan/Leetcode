class Solution {
    int mod=1e9+7;
public:
    long long f(int i, int k, int n, vector<vector<int>>& dp){
        int m=1e9+7;
        if(i<0 || i>n-1 || i>k) return 0;
        if(k==0)    return i==0;
        if(dp[i][k]!=-1)    return dp[i][k];
        return dp[i][k]=(f(i-1,k-1,n,dp)%m + f(i+1,k-1,n,dp)%m + f(i,k-1,n,dp)%m)%m;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps/2+1);
        vector<vector<int>> dp(arrLen, vector<int>(steps+1, -1));
        return f(0,steps,arrLen,dp);
    }
};
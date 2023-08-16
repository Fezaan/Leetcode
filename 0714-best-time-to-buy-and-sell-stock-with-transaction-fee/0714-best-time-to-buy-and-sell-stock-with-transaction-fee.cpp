class Solution {
public:
    int f(int i, int j, int n, int fee, vector<int>& arr, vector<vector<int>>& dp){
        if(i>=n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(j)   return dp[i][j]=max(f(i+1,0,n,fee,arr,dp)-arr[i], f(i+1,1,n,fee,arr,dp));
        return dp[i][j]=max(f(i+1,1,n,fee,arr,dp)+arr[i]-fee, f(i+1,0,n,fee,arr,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return f(0,1,n,fee,prices,dp);
    }
};
class Solution {
public:
    int f(int i, int n, int j, vector<int>& prices, vector<vector<int>>& dp){
        if(i==n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int profit=0;
        if(j){
            profit=max(-prices[i]+f(i+1,n,0,prices,dp), 
                      f(i+1,n,1,prices,dp));
            // cout<<profit<<" ";
        }else{
            profit=max(f(i+1,n,1,prices,dp)+prices[i],
                      f(i+1,n,0,prices,dp));
            // cout<<profit<<" ";
        }
        return dp[i][j]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return f(0,n,1,prices,dp);
    }
};
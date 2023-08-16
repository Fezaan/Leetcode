class Solution {
public:
    int f(int i, int j, int n, vector<int>& arr, vector<vector<int>>& dp){
        if(i==n || i==n+1 || i==n+2)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(j)   return dp[i][j]=max(f(i+1,0,n,arr,dp)-arr[i], f(i+1,1,n,arr,dp));
        return dp[i][j]=max(f(i+2,1,n,arr,dp)+arr[i], f(i+1,0,n,arr,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));
        // for(int i=n, i<=n+3;i++){
        //     for(iint j=0;i<2;i++)   dp[i][j]=0;
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j)   dp[i][j]=max(dp[i+1][0]-prices[i], dp[i+1][1]);
                else    dp[i][j]=max(dp[i+2][1]+prices[i], dp[i+1][0]);
            }
        }
        for(auto it: dp){
            for(auto j: it) cout<<j<<" ";
            cout<<endl;
        }
        return dp[0][1];
    }
};
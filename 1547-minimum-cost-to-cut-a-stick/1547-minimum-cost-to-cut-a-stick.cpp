class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        long mn=1e9;
        for(int k=i;k<=j;k++){
            long cost=(cuts[j+1]-cuts[i-1]) + f(i, k-1,cuts,dp) + f(k+1,j,cuts,dp);
            mn=min(mn,cost);
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m+3, vector<int> (m+3,0));
        for(int i=m;i>0;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                long mn=1e9;
                for(int k=i;k<=j;k++){
                    long cost=cuts[j+1]-cuts[i-1]+ dp[i][k-1]+ dp[k+1][j];
                    mn=min(mn,cost);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][m];
    }
};
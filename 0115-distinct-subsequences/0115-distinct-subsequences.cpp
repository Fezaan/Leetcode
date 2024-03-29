class Solution {
public:
    int f(int i, int j, string & a, string &b, vector<vector<int>>& dp){
        if(j==0)    return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(a[i-1]==b[j-1]){
            return dp[i][j]=f(i-1,j-1,a,b,dp)+f(i-1,j,a,b,dp);
        }
        else    return dp[i][j]=f(i-1,j,a,b,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        // return f(n,m,s,t,dp);
        for(int i=0;i<=n;i++)   dp[i][0]=1;
        // for(int j=1;j<=m;j++)   dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])  dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else    dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
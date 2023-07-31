class Solution {
public:
    int f(int m ,int n, vector<vector<int>>& dp){
        if(m==0 && n==0)    return 1;
        if(m<0 || n<0)  return 0;
        if(dp[m][n]!=-1)    return dp[m][n];
        int l=f(m,n-1,dp);
        int u=f(m-1,n,dp);
        return dp[m][n]=l+u;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,0));
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0)    dp[0][0]=1;
                else{
                    int l=0,u=0;
                    if(i>0) u=dp[i-1][j];
                    if(j>0) l=dp[i][j-1];
                    dp[i][j]=l+u;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};
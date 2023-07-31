class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0)    return grid[0][0];
        if(i<0 || j<0)  return INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];
        int l=f(i,j-1,grid,dp);
        int u=f(i-1,j,grid,dp);
        return dp[i][j]=grid[i][j]+min(l,u);
    }
    int minPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[i][j] = matrix[i][j];
                else{

                    int up = matrix[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += 1e9;

                    int left = matrix[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left += 1e9;

                    dp[i][j] = min(up,left);
                }
            }
        }
    
        return dp[n-1][m-1];
    }
};
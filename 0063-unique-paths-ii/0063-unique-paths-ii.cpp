class Solution {
public:
    int solveMEM(int i, int j, vector<vector<int>>&oG,vector<vector<int>>&dp){
        if(i>=oG.size()||j>=oG[0].size()) return 0;
        if(oG[i][j]==1) return 0;
        if(i==oG.size()-1 && j==oG[0].size()-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int right=0,down=0;
        right = solveMEM(i,j+1,oG,dp);
        down = solveMEM(i+1,j,oG,dp);
        ans = right + down;
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1)   return 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solveMEM(0,0,grid,dp);
    }
};
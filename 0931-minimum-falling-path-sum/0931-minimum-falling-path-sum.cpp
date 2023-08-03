class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int n=mat.size();
        if(j<0 || j>n-1)  return 1e9;
        if(i==0)    return mat[i][j];
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int up=mat[i][j]+f(i-1,j,mat,dp);
        int ld=mat[i][j]+f(i-1,j+1,mat,dp);
        int rd=mat[i][j]+f(i-1,j-1,mat,dp);
        
        return dp[i][j]=min(up, min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(matrix[0]);
        for(int i=1;i<n;i++){
            vector<int> tmp(n,0);
            for(int j=0;j<n;j++){
                int u=matrix[i][j]+dp[j];
                int ld=1e9,rd=1e9;
                if(j+1<n)   ld=matrix[i][j]+dp[j+1];
                if(j-1>=0) rd=matrix[i][j]+dp[j-1];
                tmp[j]=min(u,min(ld,rd));
            }
            dp=tmp;
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,dp[i]);
        }
        return mn;
    }
};
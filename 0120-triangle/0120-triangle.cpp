class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& tri, vector<vector<int>>& dp){
        if(i==n)    return tri[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int down=f(i+1,j,n,tri,dp);
        int dia=f(i+1,j+1,n,tri,dp);
        return dp[i][j]=tri[i][j]+min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(triangle[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> tmp(n,0);
            for(int j=i;j>=0;j--){
                int down=dp[j]+triangle[i][j];
                int dia=dp[j+1]+triangle[i][j];
                tmp[j]=min(down,dia);
            }
            dp=tmp;
        }
        return dp[0];
    }
};
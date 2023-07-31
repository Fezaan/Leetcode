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
        vector<vector<int>> dp;
        int n=triangle.size();
        for(int i=0;i<triangle.size();i++){
            vector<int> tmp(i+1,-1);
            dp.push_back(tmp);
        }
        dp[n-1]=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j]+triangle[i][j];
                int dia=dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
    }
};
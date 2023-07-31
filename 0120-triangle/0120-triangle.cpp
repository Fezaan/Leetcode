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
        for(int i=0;i<triangle.size();i++){
            vector<int> tmp(i+1,-1);
            dp.push_back(tmp);
        }
        return f(0,0,triangle.size()-1,triangle,dp);
    }
};
class Solution {
public:
    int f(int i, int j, int n, int m,vector<int>& a, vector<int>& b, vector<vector<int>>& dp){
        if(i==n || j==m)    return INT_MIN;
        if(dp[i][j]!=-1)    return dp[i][j];
        int prod=a[i]*b[j];
        return dp[i][j]=max(prod+max(f(i+1,j+1,n,m,a,b,dp),0), max(f(i+1,j,n,m,a,b,dp), f(i,j+1,n,m,a,b,dp)));
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,INT_MIN));
        // return f(0,0,n,m,nums1,nums2,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int prod=nums1[i-1]*nums2[j-1];
                dp[i][j]=max(prod+max(dp[i-1][j-1],0), max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};
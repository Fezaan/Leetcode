class Solution {
public:
    int f(int i, int parent,int n, vector<int>& arr, vector<vector<int>>& dp){
        if(i==n)    return 0;    
        if(dp[i][parent+1]!=-1)   return dp[i][parent+1];
        int len=f(i+1,parent,n,arr,dp);
        if(parent==-1 || arr[i]>arr[parent]){
            len=max(len,1+f(i+1,i,n,arr,dp));
        }
        return dp[i][parent+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};
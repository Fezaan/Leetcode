class Solution {
public:
    int f(int i, int k, vector<int>& arr, vector<int>& dp){
        int n=arr.size();
        if(i==n)   return 0;
        if(dp[i]!=-1)   return dp[i];
        int len=0, mx=INT_MIN,ans=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            mx=max(mx,arr[j]);
            int cost=len*mx+ f(j+1,k,arr,dp);
            ans=max(ans,cost);
        }
        return dp[i]=ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int len=0,mx,ans;
            mx=ans=INT_MIN;
            for(int j=i;j<min(i+k,n);j++){
                len++;
                mx=max(mx,arr[j]);
                int cost=len*mx+ dp[j+1];
                ans=max(ans,cost);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
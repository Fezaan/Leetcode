class Solution {
public:
    bool f(int n,int k, vector<int>& arr, vector<vector<int>>& dp){
        if(k==0)    return 1;
        if(n==0)    return arr[0]==k;
        if(dp[n][k]!=-1)    return dp[n][k];
        
        bool np= f(n-1,k,arr,dp);
        bool p=0;
        if(arr[n]<=k)   p=f(n-1,k-arr[n],arr,dp);
        
        return dp[n][k]=np|p;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(auto it: nums)  sum+=it;
        cout<<sum<<endl;
        if(sum%2==1)    return 0;
        int k=sum/2;
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return f(n-1,k,nums,dp);
    }
};
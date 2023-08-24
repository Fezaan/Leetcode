class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int mx=-1e9;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1]+ f(i,k-1,nums,dp)+ f(k+1,j,nums,dp);
            mx=max(mx,cost);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(j<i) continue;
                int mx=-1e9;
                for(int k=i;k<=j;k++){
                    int cost=nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    mx=max(mx,cost);
                }
                dp[i][j]=mx;
            }
        }
        return dp[1][n];
    }
};
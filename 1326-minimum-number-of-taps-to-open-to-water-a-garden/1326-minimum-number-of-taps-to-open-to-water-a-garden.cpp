class Solution {
public:
    // int f(int i, vector<int>& ranges, vector<int>& dp){
    //     if(i==0)    return 0;
    //     if(dp[i]!=-1)   return dp[i];
    //     int p=1e9;
    //     int np=f(i-1,ranges,dp);
    //     if()    p=1+f(i-1,ranges,dp);
    //     return dp[i]=min(p,np);
    // }
    int minTaps(int n, vector<int>& ranges) {
        vector<int> res(n+1,0);
        for(int i=0;i<=n;i++){
            if(ranges[i]==0)    continue;
            int pick=max(0,i-ranges[i]);
            res[pick]=max(res[pick],i+ranges[i]);
        }
        for(auto it: res)   cout<<it<<" ";
        int end=0, range=0, cnt=0;
        for(int i=0;i<n+1;i++){
            if(i>end){
                if(range<=end)    return -1;
                end=range;
                cnt++;  
            }
            range=max(range,res[i]);
        }
        return cnt;
    }
};
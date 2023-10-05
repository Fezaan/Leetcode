class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int n=nums.size();
        
        vector<int> dp(n+1,0), cnt(n+1,0);
        
        for(int i=0;i<n;i++){
            cnt[i]=i;
            for(int j=0;j<i;j++){
                if((nums[j]%nums[i]==0 || nums[i]%nums[j]==0) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=j;
                }
            }
        }
        int len=-1,ind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>len){
                len=dp[i];
                ind=i;
            }
        }
        res.push_back(nums[ind]);
        while(ind!=cnt[ind]){
            ind=cnt[ind];
            res.push_back(nums[ind]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
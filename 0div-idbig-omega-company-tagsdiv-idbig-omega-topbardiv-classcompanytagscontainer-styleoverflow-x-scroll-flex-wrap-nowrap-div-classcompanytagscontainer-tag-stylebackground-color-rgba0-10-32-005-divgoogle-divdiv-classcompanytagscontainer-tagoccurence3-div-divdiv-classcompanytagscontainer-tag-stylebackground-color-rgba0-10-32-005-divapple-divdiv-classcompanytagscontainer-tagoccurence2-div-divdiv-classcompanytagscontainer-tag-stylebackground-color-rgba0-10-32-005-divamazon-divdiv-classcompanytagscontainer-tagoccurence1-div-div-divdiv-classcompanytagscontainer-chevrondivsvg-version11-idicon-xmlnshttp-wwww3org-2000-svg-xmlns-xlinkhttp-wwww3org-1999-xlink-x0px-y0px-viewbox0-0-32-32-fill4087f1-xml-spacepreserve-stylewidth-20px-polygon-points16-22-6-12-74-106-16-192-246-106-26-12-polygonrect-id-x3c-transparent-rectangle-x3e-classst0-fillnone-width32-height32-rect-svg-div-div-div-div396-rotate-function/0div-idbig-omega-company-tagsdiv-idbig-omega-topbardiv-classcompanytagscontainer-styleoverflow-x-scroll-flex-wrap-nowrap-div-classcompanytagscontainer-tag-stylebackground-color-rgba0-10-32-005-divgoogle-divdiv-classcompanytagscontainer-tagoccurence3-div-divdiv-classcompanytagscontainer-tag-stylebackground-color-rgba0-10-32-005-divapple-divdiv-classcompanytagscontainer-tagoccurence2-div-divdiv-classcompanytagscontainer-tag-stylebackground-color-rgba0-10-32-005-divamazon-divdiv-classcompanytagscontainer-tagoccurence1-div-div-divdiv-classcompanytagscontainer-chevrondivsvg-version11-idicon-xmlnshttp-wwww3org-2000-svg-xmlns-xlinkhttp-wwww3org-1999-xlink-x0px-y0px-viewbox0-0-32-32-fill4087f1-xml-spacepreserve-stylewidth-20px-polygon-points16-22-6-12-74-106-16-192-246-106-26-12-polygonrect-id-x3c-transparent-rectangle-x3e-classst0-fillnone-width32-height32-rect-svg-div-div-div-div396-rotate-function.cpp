class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long mx=INT_MIN;
        int n=nums.size();
        long long  s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
            s2+=(nums[i]*i);
        }
        
        for(int i=n-1;i>=0;i--){
            s2=s2-(n-1)*nums[i]+s1-nums[i];
            mx=max(mx,s2);
        }
        return mx;
    }
};
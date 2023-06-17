class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        long long res=0;
        for(int i=0;i<n;i++){
            int amax=nums[i],amin=nums[i];
            for(int j=i;j<n;j++){
                amin=min(amin,nums[j]);
                amax=max(amax,nums[j]);
                res+=(amax-amin);
            }
        }
        return res;
    }
};
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int l,r;
        l=r=k;
        int mn=nums[k],prod=nums[k];
        while(l>0 || r<n-1){
            if(l==0 || (r<n-1 && nums[r+1]>nums[l-1]))  r++;
            else    l--;
            mn=min(mn,min(nums[l],nums[r]));
            prod=max(prod,mn*(r-l+1));
        }
        return prod;
    }
};
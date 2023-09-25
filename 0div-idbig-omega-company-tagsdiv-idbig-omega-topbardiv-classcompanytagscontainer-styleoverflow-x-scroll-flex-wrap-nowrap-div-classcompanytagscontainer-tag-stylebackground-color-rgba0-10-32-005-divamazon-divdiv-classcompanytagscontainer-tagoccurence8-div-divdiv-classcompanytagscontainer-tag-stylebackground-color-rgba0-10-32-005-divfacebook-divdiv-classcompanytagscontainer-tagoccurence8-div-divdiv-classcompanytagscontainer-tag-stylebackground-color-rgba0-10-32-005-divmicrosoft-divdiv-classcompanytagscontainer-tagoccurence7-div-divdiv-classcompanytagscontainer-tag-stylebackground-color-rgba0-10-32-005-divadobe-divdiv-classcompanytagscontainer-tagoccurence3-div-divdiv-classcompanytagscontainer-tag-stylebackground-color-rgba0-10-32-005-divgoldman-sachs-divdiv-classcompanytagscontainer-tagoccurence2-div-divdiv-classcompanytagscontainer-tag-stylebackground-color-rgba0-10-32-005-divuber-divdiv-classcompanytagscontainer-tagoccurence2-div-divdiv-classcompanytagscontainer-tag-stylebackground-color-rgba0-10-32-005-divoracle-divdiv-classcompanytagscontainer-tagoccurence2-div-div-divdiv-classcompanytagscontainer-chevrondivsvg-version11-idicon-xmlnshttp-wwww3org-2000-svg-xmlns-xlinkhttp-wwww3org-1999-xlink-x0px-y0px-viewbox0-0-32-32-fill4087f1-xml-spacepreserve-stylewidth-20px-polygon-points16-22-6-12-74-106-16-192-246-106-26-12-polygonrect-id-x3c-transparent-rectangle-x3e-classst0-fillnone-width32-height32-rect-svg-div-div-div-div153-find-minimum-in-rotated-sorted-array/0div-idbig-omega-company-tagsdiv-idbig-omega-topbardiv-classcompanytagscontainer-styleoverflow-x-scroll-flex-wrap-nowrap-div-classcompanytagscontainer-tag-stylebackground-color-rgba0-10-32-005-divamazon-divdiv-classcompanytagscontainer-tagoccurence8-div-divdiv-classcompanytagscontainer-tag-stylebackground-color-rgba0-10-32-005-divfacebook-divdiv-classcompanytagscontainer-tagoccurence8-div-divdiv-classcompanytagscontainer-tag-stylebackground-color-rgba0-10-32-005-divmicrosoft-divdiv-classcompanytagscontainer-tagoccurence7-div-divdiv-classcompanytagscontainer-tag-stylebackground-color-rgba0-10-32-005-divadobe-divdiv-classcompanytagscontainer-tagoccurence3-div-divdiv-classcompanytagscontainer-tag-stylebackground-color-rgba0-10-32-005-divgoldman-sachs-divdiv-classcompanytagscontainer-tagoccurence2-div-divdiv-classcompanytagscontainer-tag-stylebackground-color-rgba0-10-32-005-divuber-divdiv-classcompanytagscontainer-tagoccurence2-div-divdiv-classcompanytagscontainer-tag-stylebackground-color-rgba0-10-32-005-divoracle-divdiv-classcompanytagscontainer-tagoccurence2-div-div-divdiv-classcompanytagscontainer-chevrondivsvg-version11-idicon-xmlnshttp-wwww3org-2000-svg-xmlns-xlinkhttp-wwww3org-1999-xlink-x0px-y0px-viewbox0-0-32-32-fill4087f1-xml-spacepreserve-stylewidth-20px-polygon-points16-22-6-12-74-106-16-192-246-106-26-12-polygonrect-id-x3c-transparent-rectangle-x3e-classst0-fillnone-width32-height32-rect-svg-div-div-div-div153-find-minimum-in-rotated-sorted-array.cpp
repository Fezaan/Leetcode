class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        if(nums[0]<=nums[n-1])   return nums[0];
        int l=0,h=n-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(nums[m]>nums[h])    l=m+1;
            else    h=m;
        }
        return nums[l];
    }
};
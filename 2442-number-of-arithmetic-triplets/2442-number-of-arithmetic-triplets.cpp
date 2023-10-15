class Solution {
public:
    bool bs(vector<int>& arr, int target, int l){
        int h=arr.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]==target)  return 1;
            else if(arr[m]>target)  h=m-1;
            else    l=m+1;
        }
        return 0;
    }
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)  if(bs(nums,nums[i]+diff,i) && bs(nums,nums[i]+diff+diff,i))   cnt++;
        return cnt;
    }
};
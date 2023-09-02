class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
            else if(nums[l]+nums[r]>target) r--;
            else    l++;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int l=0,r=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]= abs(nums[l])>abs(nums[r])?nums[l]*nums[l++]:nums[r]*nums[r--];
        }
        return res;
    }
};
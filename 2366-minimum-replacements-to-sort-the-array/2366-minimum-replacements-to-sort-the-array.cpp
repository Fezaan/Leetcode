class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ways=0,maxMin=nums[n-1];
        for(int i=n-2;i>=0;i--){
            long long parts=ceil(nums[i]/(double)maxMin);
            ways+=(parts-1);
            maxMin=nums[i]/parts;
        }
        return ways;
    }
};
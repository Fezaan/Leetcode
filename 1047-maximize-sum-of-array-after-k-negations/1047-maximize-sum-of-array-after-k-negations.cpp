class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k--){
            *min_element(nums.begin(),nums.end())*=-1;
        }
        int sum=0;
        for(auto it: nums)  sum+=it;
        return sum;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> tmp;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))    tmp.emplace_back(nums[j]);
            }
            result.emplace_back(tmp);
        }
        return result;
    }
};

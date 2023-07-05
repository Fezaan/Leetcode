class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> v;
        if(nums.size()==0)  return v;
        sort(nums.begin(),nums.end());
        vector<int> a=nums[0];
        for(auto it: nums){
            if(it[0]<=a[1]) a[1]=max(a[1],it[1]);
            else{
                v.push_back(a);
                a=it;
            }
        }
        v.push_back(a);
        return v;
    }
};
class Solution {
public:
    void find(int index,int sum , int n, int k, vector<int> &nums, vector<vector<int>> &ans,vector<int> &ds){
        if(index==nums.size()){
            if(sum==n && ds.size()==k){
                ans.emplace_back(ds);
            }
            return;
        }
        ds.emplace_back(nums[index]);
        find(index+1,sum+nums[index],n,k,nums,ans,ds);
        ds.pop_back();
        find(index+1,sum,n,k,nums,ans,ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vect{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,0,n,k,vect,ans,ds);
        return ans;
    }
};
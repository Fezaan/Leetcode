class Solution {
public:
    void f(int i, int k, int sum, vector<int> arr, vector<vector<int>>& res, vector<int> ds){
        if(sum==k){
            res.push_back(ds);
            return;
        }
        if(i>=arr.size() || sum>k)  return;
        if(arr[i]+sum<=k){
            ds.push_back(arr[i]);
            f(i,k,sum+arr[i],arr,res,ds);
            ds.pop_back();
        }
        f(i+1,k,sum,arr,res,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        f(0,target,0,candidates,res,arr);
        return res;
    }
};
class Solution {
public:
    void f(int i, int k, int sum, vector<int> arr, vector<vector<int>>& res, vector<int> ds){
        if(sum==k){
            res.push_back(ds);
            return;
        }
        if(i>=arr.size() || sum>k)  return;
        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1]) continue;
            if(arr[j]>k)    break;
            
            ds.push_back(arr[j]);
            f(j+1,k,sum+arr[j],arr,res,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        f(0,target,0,candidates,res,ds);
        return res;
    }
};
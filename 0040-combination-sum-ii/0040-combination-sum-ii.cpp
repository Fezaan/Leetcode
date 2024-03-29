class Solution {
public:
    void find(int index, int target, vector<int> &arr, vector<vector<int>> & ans, vector<int> &ds){
            if(target==0){
                ans.emplace_back(ds);
                return;
            }
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            find(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        find(0,target,candidates,res,ds);
        return res;
    }
};
class Solution {
public:
    void f(int i, int sz, int k, vector<vector<int>>& res, vector<int> ds, vector<int>& arr){
        if(i==arr.size()){
            if(k==0 && ds.size()==sz){
                res.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[i]);
        f(i+1,sz,k-arr[i],res,ds,arr);
        ds.pop_back();
        f(i+1,sz,k,res,ds,arr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> ds;
        f(0,k,n,res,ds,arr);
        return res;
    }
};
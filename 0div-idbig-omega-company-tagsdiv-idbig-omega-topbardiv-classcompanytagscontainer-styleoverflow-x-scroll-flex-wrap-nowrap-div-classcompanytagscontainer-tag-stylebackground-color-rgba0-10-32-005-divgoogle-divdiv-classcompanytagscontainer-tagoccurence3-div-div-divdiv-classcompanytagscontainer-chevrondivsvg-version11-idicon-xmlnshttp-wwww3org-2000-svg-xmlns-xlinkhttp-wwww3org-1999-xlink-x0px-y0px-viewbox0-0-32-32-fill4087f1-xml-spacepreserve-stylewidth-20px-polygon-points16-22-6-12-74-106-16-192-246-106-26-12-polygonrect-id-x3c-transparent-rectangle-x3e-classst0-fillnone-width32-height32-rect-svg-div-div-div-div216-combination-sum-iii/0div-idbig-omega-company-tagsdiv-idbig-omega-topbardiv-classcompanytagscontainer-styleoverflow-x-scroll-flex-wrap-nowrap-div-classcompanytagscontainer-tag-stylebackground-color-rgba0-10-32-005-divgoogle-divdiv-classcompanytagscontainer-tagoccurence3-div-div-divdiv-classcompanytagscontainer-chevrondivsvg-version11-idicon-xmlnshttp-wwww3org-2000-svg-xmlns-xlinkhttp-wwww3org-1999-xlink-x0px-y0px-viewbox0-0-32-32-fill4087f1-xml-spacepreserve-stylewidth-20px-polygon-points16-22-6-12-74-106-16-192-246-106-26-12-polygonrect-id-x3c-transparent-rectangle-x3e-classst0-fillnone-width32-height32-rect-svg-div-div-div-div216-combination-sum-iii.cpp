class Solution {
public:
    void f(int i, int sz, int k, vector<vector<int>>& res, vector<int> ds){
        if(i==9){
            if(k==0 && ds.size()==sz){
                res.push_back(ds);
            }
            return;
        }
        ds.push_back(i+1);
        f(i+1,sz,k-i-1,res,ds);
        ds.pop_back();
        f(i+1,sz,k,res,ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        f(0,k,n,res,ds);
        return res;
    }
};
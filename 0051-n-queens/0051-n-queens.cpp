class Solution {
public:
    void find(int index, int n, vector<vector<string>> &res, vector<string> &ds, vector<int> &arr, vector<int> &brr, vector<int> &crr){
        if(index==n){
            res.emplace_back(ds);
            return;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && brr[i+index]==0 && crr[n-1-i+index]==0){
                ds[i][index]='Q';
                arr[i]=brr[i+index]=crr[n-1+index-i]=1;
                find(index+1,n,res,ds,arr,brr,crr);
                ds[i][index]='.';
                arr[i]=brr[i+index]=crr[n-1+index-i]=0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ds(n);
        string s(n,'.');
        for(int i=0;i<n;i++)    ds[i]=s;
        vector<int> arr(n,0), brr(2*n-1,0), crr(2*n-1,0);
        find(0,n,res,ds,arr,brr,crr);
        return res;
    }
};
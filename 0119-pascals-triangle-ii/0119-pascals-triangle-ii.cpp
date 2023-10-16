class Solution {
public:
    int nCr(int n, int r){
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)/i;
        }
        return (int)res;
    }
    vector<int> getRow(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(nCr(n,i));
        }
        return res;
    }
};
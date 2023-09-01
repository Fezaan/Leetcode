class Solution {
public:
    // int cntBits(int n){
    //     int cnt=0;
    //     while(n){
    //         cnt+=n&1;
    //         n=n>>1;
    //     }
    //     return cnt;
    // }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++){
            res[i]=__builtin_popcount(i);
        }
        return res;
    }
};
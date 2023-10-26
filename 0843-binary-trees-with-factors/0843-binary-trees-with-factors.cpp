const int mod= 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> dp;
        for(auto it: arr)   dp[it]=1;
        for(auto it: arr){
            for(auto jt: arr){
                if(jt > sqrt(it))   break;
                if(it%jt==0 && st.find(it/jt)!=st.end()){
                    long long tmp=(long long)dp[jt]*dp[it/jt];
                    if(it/jt == jt) dp[it]=(dp[it]+tmp)%mod;
                    else    dp[it]=(dp[it]+tmp*2)%mod;
                }
            }
        }
        int sum=0;
        for(auto it: dp)    sum= (sum+it.second)%mod;
        return sum;
    }
};
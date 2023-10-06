class Solution {
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
public:
    bool check(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;

        int first = 0;
        int second = 0;

        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        
        sort(arr.begin(), arr.end(),comp);
        
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(arr[i],arr[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=1;
        for(auto it: dp)    cout<<it<<" ";
        for(auto it: dp)    if(it>ans)  ans=it;
        return ans;
    }
};
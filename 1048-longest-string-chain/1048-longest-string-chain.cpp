class Solution {
public:
    bool compare(string& s1, string& s2){
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
    
    int longestStrChain(vector<string>& word) {
        int n=word.size();
        sort(word.begin(), word.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
        vector<int> dp(n+1,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(word[i],word[j]) && 1+dp[j]>dp[i])   dp[i]=1+dp[j];
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};
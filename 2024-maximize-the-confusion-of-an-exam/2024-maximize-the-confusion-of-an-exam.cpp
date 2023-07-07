class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        unordered_map<char,int> mp;
        int l=0,r=0,freq=0;
        while(r<ans.size()){
            mp[ans[r]]++;
            freq=max(freq,mp[ans[r]]);
            if(freq+k< (r-l+1)){
                mp[ans[l]]--;
                l++;
            }
            r++;
        }
        return ans.size()-l;
    }
};
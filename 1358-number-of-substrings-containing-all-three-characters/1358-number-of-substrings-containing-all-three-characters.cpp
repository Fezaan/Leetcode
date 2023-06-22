class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,count=0;
        
        while(r<s.length()){
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                count+=s.length()-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};
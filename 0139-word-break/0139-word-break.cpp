class Solution {
public:
    unordered_map<string,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()==0)   return true;
        if(mp.find(s)==mp.end()){
            for(auto it: wordDict){
                if(it.length()>s.length())  continue;
                if(s.substr(0,it.length())==it){
                    if(wordBreak(s.substr(it.length()),wordDict))
                        return true;
                }
            }
        }
        mp[s]=false;
        return false;
    }
};
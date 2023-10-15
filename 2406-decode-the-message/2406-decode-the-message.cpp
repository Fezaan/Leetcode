class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        char ch='a';
        for(auto it: key){
            if(it==' ') continue;
            if(mp.find(it)!=mp.end())   continue;
            mp[it]=ch++;
        }
        for(auto it: mp){
            cout<<it.first<<"-"<<it.second<<endl;
        }
        string res;
        for(auto it: message){
            if(it==' ') res+=it;
            else{
                res+=mp[it];
            }
        }
        return res;
    }
};
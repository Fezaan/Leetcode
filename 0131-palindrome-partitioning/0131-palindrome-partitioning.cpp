class Solution {
public:

bool pall(int start, int end, string s){
    while(start<=end){
        if(s[start++]!=s[end--])    return false;
    }
    return true;
}
void find(int index, string s, vector<vector<string>> &res, vector<string> &ds){
    if(index==s.length()){
        res.emplace_back(ds);
        return;
    }
    for(int i=index;i<s.length();i++){
        if(pall(index,i,s)){
            ds.push_back(s.substr(index,i-index+1));
            find(i+1,s,res,ds);
            ds.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        find(0,s,res,ds);
        return res;
    }
};
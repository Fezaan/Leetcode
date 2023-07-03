class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())   return 0;
        if(s==goal){
            unordered_map<char,int> mp;
            for(auto it: s){
                mp[it]++;
                if(mp[it]>1)    return 1;
            }
            return 0;
        }
        int l=0,cnt=2;
        vector<int> res;
        while(l<s.size() && cnt>0){
            if(s[l]!=goal[l])   res.push_back(l);
            l++;
            // cout<<s[l]<<" "<<goal[l]<<" "<<cnt<<endl;
        }
        return res.size()==2 && s[res[0]]==goal[res[1]] && s[res[1]]==goal[res[0]];
    }
};
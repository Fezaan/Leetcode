class Solution {
public:
    int largestVariance(string s) {
        vector<int> mp(26,0);
        for(auto it: s) mp[it-'a']++;
        int diff=0;
        
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(i==j || mp[i-'a']==0 || mp[j-'a']==0)    continue;
                for(int k=0;k<2;k++){
                    int a=0,b=0;
                    for(auto it: s){
                        if(it==i)   a++;
                        if(it==j)   b++;
                        if(b>a) a=b=0;
                        if(a>0 && b>0)  diff=max(diff,a-b);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return diff;
    }
};
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=0;
        for(auto it: sentences){
            int cnt=0;
            for(auto j: it){
                if(j==' ')  cnt++;
            }
            mx=max(mx,cnt+1);
        }
    return mx;
    }
};
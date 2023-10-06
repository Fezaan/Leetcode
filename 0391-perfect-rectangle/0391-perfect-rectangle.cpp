class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long ,int> mp;
        const long long n=1000000;
        for(auto it: rectangles){
            int x=it[0],y=it[1],a=it[2],b=it[3];
            mp[x*n+y]++;
            mp[x*n+b]--;
            mp[a*n+y]--;
            mp[a*n+b]++;
        }
        int corners=0;
        for(auto it: mp){
            if(it.second!=0){
                if(abs(it.second)!= 1)  return 0;
                corners++;
            }
        }
        return corners==4;
    }
};
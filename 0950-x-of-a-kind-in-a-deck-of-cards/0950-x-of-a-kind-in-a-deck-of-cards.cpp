class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1)    return 0;
        unordered_map<int,int> mp;
        for(auto it: deck)  mp[it]++;
        int num=0;
        for(auto it: mp){
            num=gcd(it.second,num);
        }
        return num>1;
    }
};
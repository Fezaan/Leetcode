class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums)  mp[it]++;
        int res=0;
        for(auto it: mp)    if(it.second==1)    res=it.first;
        return res;
    }
};
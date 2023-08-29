class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
            if(mp[it]>1)    return 1;
        }
        // for(auto it: mp)    cout<<it.first<<"-"<<it.second<<endl;
        return 0;
    }
};
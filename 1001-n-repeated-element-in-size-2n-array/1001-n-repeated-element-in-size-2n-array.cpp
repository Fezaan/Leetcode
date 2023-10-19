class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> mp;
        for(auto it: nums)  mp[it]++;
        for(auto it: mp){
            if(it.second==n/2)  res=it.first;
        }
        return res;
    }
};
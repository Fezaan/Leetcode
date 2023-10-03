class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int> mp;
        for(auto it: nums)  mp[it]++;
        for(auto it: mp){
            int x=it.second;
            cnt+=((x-1)*x/2);
        }
        return cnt;
    }
};
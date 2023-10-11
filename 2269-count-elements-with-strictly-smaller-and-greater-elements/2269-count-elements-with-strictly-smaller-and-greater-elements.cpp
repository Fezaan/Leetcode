class Solution {
public:
    int countElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums)  mp[it]++;
        if(mp.size()<3) return 0;
        int cnt=0;
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        for(auto it: mp){
            if(it.first==mx || it.first==mn)  continue;
            cnt+=it.second;
        }
        return cnt;
    }
};
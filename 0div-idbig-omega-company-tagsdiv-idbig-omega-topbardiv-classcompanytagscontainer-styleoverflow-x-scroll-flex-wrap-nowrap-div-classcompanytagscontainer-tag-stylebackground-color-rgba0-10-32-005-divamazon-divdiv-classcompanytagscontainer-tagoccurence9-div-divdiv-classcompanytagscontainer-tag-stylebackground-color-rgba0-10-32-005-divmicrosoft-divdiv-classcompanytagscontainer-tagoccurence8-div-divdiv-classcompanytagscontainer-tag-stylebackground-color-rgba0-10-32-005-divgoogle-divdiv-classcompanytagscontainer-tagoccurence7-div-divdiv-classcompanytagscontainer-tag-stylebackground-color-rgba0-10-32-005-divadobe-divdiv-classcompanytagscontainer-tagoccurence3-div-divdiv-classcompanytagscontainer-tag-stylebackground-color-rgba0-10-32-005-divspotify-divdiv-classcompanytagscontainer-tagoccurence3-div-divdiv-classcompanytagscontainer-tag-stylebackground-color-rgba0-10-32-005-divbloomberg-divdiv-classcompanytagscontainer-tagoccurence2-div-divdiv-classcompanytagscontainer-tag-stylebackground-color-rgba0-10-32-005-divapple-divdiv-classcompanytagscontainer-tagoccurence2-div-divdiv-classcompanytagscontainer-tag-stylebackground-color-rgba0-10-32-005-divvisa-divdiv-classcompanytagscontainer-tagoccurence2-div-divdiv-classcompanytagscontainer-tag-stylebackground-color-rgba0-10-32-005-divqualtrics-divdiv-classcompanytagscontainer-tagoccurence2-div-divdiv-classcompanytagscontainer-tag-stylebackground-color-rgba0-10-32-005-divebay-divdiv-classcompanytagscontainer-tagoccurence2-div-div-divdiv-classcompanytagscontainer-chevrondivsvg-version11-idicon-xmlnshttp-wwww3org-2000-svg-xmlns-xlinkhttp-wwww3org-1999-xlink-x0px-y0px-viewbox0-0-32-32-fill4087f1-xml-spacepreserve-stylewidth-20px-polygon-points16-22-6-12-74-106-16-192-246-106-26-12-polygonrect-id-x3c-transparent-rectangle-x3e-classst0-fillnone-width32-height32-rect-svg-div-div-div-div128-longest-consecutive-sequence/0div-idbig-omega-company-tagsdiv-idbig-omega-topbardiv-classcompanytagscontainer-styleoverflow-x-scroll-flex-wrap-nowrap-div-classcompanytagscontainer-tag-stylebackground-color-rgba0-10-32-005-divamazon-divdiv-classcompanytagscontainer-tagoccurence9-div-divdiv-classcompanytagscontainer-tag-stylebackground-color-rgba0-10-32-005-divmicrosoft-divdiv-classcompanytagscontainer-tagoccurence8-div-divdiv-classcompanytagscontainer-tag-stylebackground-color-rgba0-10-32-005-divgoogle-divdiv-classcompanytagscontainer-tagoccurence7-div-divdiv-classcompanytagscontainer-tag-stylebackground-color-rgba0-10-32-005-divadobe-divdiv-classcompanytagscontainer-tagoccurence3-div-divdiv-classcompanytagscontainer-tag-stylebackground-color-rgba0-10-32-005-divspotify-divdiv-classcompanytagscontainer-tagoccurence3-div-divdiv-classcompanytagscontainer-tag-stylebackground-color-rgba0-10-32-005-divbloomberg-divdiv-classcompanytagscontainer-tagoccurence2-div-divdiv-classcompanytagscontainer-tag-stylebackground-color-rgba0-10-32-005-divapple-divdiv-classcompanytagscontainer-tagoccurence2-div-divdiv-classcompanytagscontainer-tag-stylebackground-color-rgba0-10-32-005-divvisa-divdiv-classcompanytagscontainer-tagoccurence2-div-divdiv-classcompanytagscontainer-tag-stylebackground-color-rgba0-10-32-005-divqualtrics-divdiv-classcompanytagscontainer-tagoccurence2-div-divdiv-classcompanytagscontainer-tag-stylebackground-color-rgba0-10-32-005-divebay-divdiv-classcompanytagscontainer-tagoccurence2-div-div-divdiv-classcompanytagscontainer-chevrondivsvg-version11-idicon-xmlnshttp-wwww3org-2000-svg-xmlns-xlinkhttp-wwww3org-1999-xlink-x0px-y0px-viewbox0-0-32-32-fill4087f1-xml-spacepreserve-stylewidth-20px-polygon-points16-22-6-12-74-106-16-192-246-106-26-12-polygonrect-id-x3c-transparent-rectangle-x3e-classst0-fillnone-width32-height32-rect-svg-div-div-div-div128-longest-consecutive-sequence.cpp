class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int mx=0;
        for(auto &it: nums){
            if(!s.count(it-1)){
                int cnt=1;
                while(s.count(it+cnt))  cnt++;
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};
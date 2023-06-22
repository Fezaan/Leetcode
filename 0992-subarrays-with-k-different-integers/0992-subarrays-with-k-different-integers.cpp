class Solution {
public:
    int count(vector<int>& nums, int k) {
        int res=0,l=0,r=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)  mp.erase(nums[l]);
                l++;
            }
            res+=r-l+1;
            r++;
        }
        
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};

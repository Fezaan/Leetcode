class Solution {
public:
    int count(vector<int> & nums, int goal){
        if(goal<0) return 0;
        int res=0,r=0,l=0;
        int sum=0;
        
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal) sum-=nums[l++];
            int len=r-l+1;
            res+=len;
            
            r++;
        }
        
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return count(nums,goal)-count(nums,goal-1);
    }
};
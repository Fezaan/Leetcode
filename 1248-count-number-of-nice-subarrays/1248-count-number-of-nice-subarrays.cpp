class Solution {
public:
    int count(vector<int> & nums, int k){
        if(k<0) return 0;
        int res=0,r=0,l=0,tot=0;
        
        while(r<nums.size()){
            if(nums[r]%2)   tot++;
            while(tot>k){
                if(nums[l]%2)   tot--;
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int len=0;
        int count=0;
        deque<int> q;
        while(r<n){
            if(nums[r]==0){
                count++;
            }
            if(count>k){
                while(nums[l]!=0)   l++;
                l++;
                count--;
            }

            len=max(len,r-l+1);
            r++;

        }
        return len;
    }
};
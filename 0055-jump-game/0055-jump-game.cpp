class Solution {
public:
    bool canJump(vector<int>& nums) {
        int e=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=e)    e=i;
        }
        return e==0;
    }
};
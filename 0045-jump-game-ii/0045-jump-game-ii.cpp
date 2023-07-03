class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,cnt=0;
        while(r<nums.size()-1){
            int far=-1;
            for(int i=l;i<=r;i++)   far=max(far,i+nums[i]);
            l=r+1;
            r=far;
            cnt++;
        }
        return cnt;
    }
};
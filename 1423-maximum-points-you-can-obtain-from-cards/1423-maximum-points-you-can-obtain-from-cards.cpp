class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<k;i++)    sum+=nums[i];
        int curr=sum;
        for(int i=k-1;i>=0;i--){
            curr-=nums[i];
            curr+=nums[n-k+i];
            sum=max(curr,sum);
        }
        return sum;
    }
};
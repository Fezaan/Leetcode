class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int mx=nums[0];
        deque<int> dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            dq.empty()? nums[i]+=0: nums[i]+=dq.front();
            mx=max(mx,nums[i]);
            while(!dq.empty() && nums[i]>dq.back()) dq.pop_back();
            if(nums[i]>0)   dq.push_back(nums[i]);
            if(i>=k && !dq.empty() && nums[i-k]==dq.front())    dq.pop_front();
        }
        return mx;
    }
};
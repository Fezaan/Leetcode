class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res=nums[0], n=nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({res,0});
        for(int i=1;i<n;i++){
            while(i-pq.top().second>k)  pq.pop();
            int mx=max(nums[i],pq.top().first+nums[i]);
            res=max(mx,res);
            pq.push({mx,i});

        }
        return res;
    }
};
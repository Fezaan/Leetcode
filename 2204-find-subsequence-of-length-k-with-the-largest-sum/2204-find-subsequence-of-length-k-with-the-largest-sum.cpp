class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq,tmp;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            while(pq.size()>k)  pq.pop();
        }
        while(!pq.empty()){
            tmp.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        while(!tmp.empty()){
            res.push_back(tmp.top().second);
            tmp.pop();
        }

        return res;
    }
};
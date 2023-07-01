typedef pair<int,int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<p,vector<p>,greater<p>> pq;
        // priority_queue<p> pq;
        for(auto it: nums)  mp[it]++;
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
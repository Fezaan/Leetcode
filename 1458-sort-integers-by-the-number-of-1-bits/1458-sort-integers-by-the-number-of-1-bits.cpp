class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto it: arr)   pq.push({__builtin_popcount(it),it});
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
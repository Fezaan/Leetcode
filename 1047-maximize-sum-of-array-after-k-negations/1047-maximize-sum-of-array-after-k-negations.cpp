class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> pq(nums.begin(),nums.end());
        while(k--){
            int tmp=pq.top();
            pq.pop();
            pq.push(tmp*-1);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
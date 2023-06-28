class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& div) {
        int x=0;
        for(auto it: div){
            x=gcd(x,it);
        }
        cout<<x;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it: nums)  pq.push(it);
        int count=0;
        while(!pq.empty() && x%pq.top()){
            count++;
            pq.pop();
        }
        if(pq.empty())  return -1;
        return count;
    }
};


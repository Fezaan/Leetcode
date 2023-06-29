class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        priority_queue<int> pq;
        
        for(auto it: tasks){
            mp[it-'A']++;
        }
        
        for(int i=0;i<26;i++){
            if(mp[i]>0) pq.push(mp[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> rem;
            int cycle=n+1;
            
            while(cycle && !pq.empty()){
                int freq=pq.top();
                pq.pop();
                if(freq>1)  rem.push_back(freq-1);
                time++;
                cycle--;
            }
            for(auto it: rem){
                pq.push(it);
            }
            
            if(pq.empty())  break;
            time+=cycle;
            
        }
        return time;
    }
};
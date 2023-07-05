class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> & b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int goal=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<goal)   cnt++;
            else    goal=intervals[i][1];
        }
        return cnt;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0,mx=0;
        if (nums.size()==0){
            return 0;
        }
        set<int> s;
        for(auto it: nums)  s.emplace(it);
        for(auto it=s.begin();next(it)!=s.end();++it){
            if((*next(it,1))-(*it)==1){
                count++;
                mx=max(mx,count);
            }
            else{
                mx=max(mx,count);  count=0;
            }
        }
        return mx+1;
    }
};
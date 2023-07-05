class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> data;
        int cnt=0,zero=0;
        for(auto it: nums){
            if(it==0){
                data.push_back(cnt);
                cnt=0;
                zero++;
            }
            else    cnt++;
        }
        data.push_back(cnt);
        
        if(zero==0) return nums.size()-1;
        
        for(auto it: data)  cout<<it<<" ";
        int sum=0;
        for(int i=1;i<data.size();i++){
            sum=max(sum,data[i]+data[i-1]);
        }
        
        return sum;
    }
};
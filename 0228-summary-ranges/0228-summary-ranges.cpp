class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)  return {};
        vector<string> ans;
        int start=nums[0],end=nums[0];
        for(int i=1;i<nums.size();i++){
            if(end+1==nums[i]){
                end=nums[i];
            }
            else{
                if(start==end){
                    ans.emplace_back(to_string(start));
                }
                else{
                    string x=to_string(start)+"->"+to_string(end);
                    ans.emplace_back(x);
                }
                start=end=nums[i];
            }
            cout<<start<<" "<<end<<" "<<i<<","<<i+1<<endl;
        }
        if(start==end){
            ans.emplace_back(to_string(start));
        }else{
            string x=to_string(start)+"->"+to_string(end);
            ans.emplace_back(x);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cnt=1;
        for(auto it: target){
            while(it!=cnt){
                res.push_back("Push");
                res.push_back("Pop");
                cnt++;
            }
            if(it==cnt){
                res.push_back("Push");
                cnt++;
            }
        }
        return res;
    }
};
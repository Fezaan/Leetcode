class Solution {
    void generateParenthesis(int n, string curr, int open, int close, vector<string> &res){
        if(curr.length()==2*n){
            res.push_back(curr);
        }
        else{
            if(open<n){
                generateParenthesis(n,curr+"(",open+1,close,res);
            }
            if(close<open){
                generateParenthesis(n,curr+")",open,close+1,res);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n,"",0,0,res);
        return res;
    }
};
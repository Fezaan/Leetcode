class Solution {
public:
    void find(int index, string arr[],string digits, vector<string>& res, string ds){
        if(index>=digits.length()){
            res.emplace_back(ds);
            return;
        }
        int num=digits[index]-'0';
        string val=arr[num];
        
        for(int i=0;i<val.length();i++){
            ds.push_back(val[i]);
            find(index+1,arr,digits,res,ds);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0)  return res;
        string arr[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ds="";
        find(0, arr,digits,res,ds);
        return res;
    }
};
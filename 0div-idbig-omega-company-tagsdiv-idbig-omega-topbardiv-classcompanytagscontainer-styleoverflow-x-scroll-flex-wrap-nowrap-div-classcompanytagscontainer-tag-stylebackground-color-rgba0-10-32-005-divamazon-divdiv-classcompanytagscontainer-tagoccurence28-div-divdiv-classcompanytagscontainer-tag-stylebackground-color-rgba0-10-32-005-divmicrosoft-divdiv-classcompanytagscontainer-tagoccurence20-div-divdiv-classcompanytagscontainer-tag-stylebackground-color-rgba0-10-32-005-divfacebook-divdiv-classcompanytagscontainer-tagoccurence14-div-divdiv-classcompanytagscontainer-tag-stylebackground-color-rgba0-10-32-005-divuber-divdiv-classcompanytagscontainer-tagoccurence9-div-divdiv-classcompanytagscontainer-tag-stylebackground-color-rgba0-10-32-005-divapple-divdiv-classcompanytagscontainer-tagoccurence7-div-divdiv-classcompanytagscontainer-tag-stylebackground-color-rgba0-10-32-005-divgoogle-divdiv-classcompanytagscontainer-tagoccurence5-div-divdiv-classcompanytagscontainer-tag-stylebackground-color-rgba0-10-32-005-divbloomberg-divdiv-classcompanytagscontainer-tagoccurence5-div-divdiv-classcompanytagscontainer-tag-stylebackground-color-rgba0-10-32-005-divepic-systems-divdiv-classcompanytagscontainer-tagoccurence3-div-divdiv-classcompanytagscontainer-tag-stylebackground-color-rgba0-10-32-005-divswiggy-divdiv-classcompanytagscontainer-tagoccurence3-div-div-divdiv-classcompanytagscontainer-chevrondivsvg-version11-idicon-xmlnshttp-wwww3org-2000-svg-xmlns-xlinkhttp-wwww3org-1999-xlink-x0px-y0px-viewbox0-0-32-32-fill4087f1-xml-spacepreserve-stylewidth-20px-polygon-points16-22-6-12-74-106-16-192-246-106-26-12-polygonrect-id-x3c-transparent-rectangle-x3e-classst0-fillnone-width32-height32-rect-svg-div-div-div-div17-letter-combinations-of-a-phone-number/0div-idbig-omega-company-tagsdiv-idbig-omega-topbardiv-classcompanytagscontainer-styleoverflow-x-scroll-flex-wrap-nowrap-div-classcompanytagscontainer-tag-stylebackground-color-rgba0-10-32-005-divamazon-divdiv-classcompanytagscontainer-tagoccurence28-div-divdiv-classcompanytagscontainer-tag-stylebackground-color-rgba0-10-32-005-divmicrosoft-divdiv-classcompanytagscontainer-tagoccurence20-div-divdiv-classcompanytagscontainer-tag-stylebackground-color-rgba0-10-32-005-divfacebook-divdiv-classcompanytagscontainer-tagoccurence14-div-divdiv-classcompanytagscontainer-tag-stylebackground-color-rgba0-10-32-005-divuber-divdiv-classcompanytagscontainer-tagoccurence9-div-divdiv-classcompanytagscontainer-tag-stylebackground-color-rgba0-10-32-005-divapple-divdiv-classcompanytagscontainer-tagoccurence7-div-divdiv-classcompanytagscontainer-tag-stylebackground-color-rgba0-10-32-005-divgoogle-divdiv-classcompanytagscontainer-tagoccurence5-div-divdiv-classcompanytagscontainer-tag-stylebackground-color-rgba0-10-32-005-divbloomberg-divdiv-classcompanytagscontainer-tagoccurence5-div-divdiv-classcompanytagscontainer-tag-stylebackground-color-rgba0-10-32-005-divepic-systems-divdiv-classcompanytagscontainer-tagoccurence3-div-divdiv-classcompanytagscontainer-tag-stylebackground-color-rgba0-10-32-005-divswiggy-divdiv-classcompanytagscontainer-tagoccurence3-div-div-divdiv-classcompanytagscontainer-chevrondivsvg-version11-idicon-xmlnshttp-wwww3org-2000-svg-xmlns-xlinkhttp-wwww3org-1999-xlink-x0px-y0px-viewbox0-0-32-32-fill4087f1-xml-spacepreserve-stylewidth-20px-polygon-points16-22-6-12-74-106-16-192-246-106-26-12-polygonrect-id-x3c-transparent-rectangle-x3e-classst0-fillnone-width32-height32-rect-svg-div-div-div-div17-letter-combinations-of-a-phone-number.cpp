class Solution {
public:
    void f(int i, string arr, vector<string>& res, string ds, vector<string>& tab){
        if(i>=arr.size()){
            res.push_back(ds);
            return;
        }
        string test=tab[arr[i]-'0'];
        for(int j=0;j<test.size();j++){
            ds.push_back(test[j]);
            f(i+1,arr,res,ds,tab);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)    return {};
        vector<string> res;
        string ds="";
        vector<string> arr{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,digits,res,ds,arr);
        return res;
    }
};
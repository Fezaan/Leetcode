class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        int n=s.size();
        if(n<=numRows)  return s;
        string res;
        int cycleLen=2*numRows-2;
        for(int i=0;i<numRows;i++){
            for(int j=0;(j+i)<n;j+=cycleLen){
                res.push_back(s[j+i]);
                if(i!=0 && i!=(numRows-1) && (j+cycleLen-i)<n)  res.push_back(s[j+cycleLen-i]);
            }
        }
        return res;
    }
};
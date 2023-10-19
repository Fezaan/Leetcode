class Solution {
public:
    bool isValid(string s){
        int n=s.size();
        int cnt=0;
        if(n==0)    return 0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))   return 0;
            if(isalpha(s[i])) continue;
            else if(s[i]=='-'){
                if(i==0 || i==n-1)  return 0;
                if(islower(s[i-1]) && islower(s[i+1]))  cnt++;
                else   return 0;
            }
            else if(s[i]=='!' || s[i]=='.' || s[i]==','){
                if(i==n-1)  continue;
                else    return 0;
            }
        }
        if(cnt>1)   return 0;
        return 1;
    }
    int countValidWords(string sentence) {
        int cnt=0;
        string word;
        for(auto it: sentence){
            if(it==' '){
                if(isValid(word))   cnt++;
                word="";
                continue;
            }
            else{
                word+=it;
            }
        }
        if(isValid(word))   cnt++;
        return cnt;
    }
};
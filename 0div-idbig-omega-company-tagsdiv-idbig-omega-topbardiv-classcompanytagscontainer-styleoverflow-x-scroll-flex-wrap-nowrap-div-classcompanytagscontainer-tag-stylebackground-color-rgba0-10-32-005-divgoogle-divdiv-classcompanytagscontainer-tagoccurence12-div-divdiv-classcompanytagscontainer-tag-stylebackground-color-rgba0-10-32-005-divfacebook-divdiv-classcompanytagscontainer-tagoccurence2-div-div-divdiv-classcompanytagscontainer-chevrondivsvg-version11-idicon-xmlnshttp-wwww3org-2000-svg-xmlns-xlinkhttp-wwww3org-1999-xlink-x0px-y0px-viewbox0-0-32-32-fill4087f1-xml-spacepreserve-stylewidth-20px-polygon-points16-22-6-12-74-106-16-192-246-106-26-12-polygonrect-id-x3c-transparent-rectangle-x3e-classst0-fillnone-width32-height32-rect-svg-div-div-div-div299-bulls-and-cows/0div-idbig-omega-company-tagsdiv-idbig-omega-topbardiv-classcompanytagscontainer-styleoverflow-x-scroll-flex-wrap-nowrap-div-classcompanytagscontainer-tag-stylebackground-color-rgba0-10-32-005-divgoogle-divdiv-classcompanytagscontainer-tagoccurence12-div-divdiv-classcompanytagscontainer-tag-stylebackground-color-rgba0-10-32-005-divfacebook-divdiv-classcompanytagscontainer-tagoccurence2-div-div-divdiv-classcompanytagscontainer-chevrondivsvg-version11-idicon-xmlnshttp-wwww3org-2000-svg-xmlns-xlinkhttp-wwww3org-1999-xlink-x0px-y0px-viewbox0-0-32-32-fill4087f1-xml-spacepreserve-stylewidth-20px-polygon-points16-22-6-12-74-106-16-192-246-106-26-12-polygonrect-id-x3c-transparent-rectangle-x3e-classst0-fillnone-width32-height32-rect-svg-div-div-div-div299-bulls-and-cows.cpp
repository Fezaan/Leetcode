class Solution {
public:
    string getHint(string secret, string guess) {
        string res="";
        int bulls=0;
        int i=0,n=secret.size();
        while(i<n){
            if(secret[i]==guess[i]) bulls++;
            i++;
        }
        res+=(to_string(bulls)+'A');
        int cows=0;
        sort(secret.begin(),secret.end());
        sort(guess.begin(),guess.end());
        int j=0;
        i=0;
        while(j<n && i<n){
            if(secret[i]==guess[j]){
                cows++;
                i++;
                j++;
            }
            else{
                if(secret[i]-'0' > guess[j]-'0')    j++;
                else    i++;
            }
        }
        res+=(to_string(cows-bulls)+'B');
        return res;
    }
};
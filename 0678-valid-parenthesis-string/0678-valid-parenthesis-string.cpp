class Solution {
public:
    bool checkValidString(string s) {
        int o=0,star=0,u=0;
        for(auto c: s){
            if(c=='(')  o++;
            else if(c=='*'){
                if(o>0){
                    u++;
                    o--;
                }
                else    star++;
            }
            else{
                if(o>0) o--;
                else if(star>0) star--;
                else if(u>0){
                    u--;
                    star++;
                }
                else    return 0;
            }
        }
        return o==0;
    }
};
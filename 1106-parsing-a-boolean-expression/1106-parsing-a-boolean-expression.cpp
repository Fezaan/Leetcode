class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> s;
        for(auto it: exp){
            if(it==')'){
                bool hast=0, hasf=0;
                while(s.top()!='('){
                    char ch=s.top();
                    s.pop();
                    if(ch=='t') hast=1;
                    if(ch=='f') hasf=1;
                }
                s.pop();
                char op=s.top();
                s.pop();
                if(op=='&'){
                    bool val= hasf?0:1;
                    if(val) s.push('t');
                    else    s.push('f');   
                }
                else if(op=='|'){
                    bool val= hast?1:0;
                    if(val) s.push('t');
                    else    s.push('f');   
                }
                else{
                    if(hast)    s.push('f');
                    else    s.push('t');
                }
            }
            else    s.push(it);
        }
        char res=s.top();
        s.pop();
        return res=='t'?1:0;
    }
};
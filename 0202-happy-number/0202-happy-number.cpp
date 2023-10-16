class Solution {
public:
    int sqSum(int n){
        int cnt=0;
        while(n!=0){
            int digit=n%10;
            cnt+=digit*digit;
            n/=10;
        }
        return cnt;
    }
    bool isHappy(int n) {
        int s,f;
        s=f=n;
        do{
            s=sqSum(s);
            f=sqSum(f);
            f=sqSum(f);
        }while(s!=f);
        return s==1;
    }
};
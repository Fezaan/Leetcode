class Solution {
public:
    int kthGrammar(int n, int k) {
        int cnt=0, org=0;
        while(n>1){
            int maxk=pow(2,n-1);
            if(k <= (int)maxk/2){
                n--;
                continue;
            }
            cnt++;
            k-=(maxk/2);
            n--;
        }
        return cnt%2;
    }
};
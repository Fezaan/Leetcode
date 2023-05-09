#define M 1000000007;
class Solution {
public:
    long long power(long long x, long long n){
        if(n==0)    return 1;
        long long ans= power(x,n/2);
        ans*=ans;
        ans%=M;
        if(n%2==1){
            ans*=x;
            ans%=M;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return (power(5,n/2)*power(4,n/2))%M;
        }
        else{
            return (power(5,n/2+1)*power(4,n/2))%M;
        }   
    }
};



class Solution {
public:
    int findSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int n) {
        int sum=findSum(n);
        while(sum>9){
            sum=findSum(sum);
        }
        return sum;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)    return x;
        int l=1,h=x;
        while(l<=h){
            int mid=l+ (h-l)/2;
            if((long)mid*mid==(long)x)  return mid;
            else if((long)mid*mid>(long)x)  h=mid-1;
            else  l=mid+1;
        }
        return h;
    }
};

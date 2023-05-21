class Solution {
public:
    bool isPowerOfTwo(int x) {
        if(x<=0)    return false;
        if((x&(x-1))==0)  return true;
        return false;
    }
};
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bsearchl(int s, int e, MountainArray &mountainArr, int target){
int mid = s+(e-s)/2;
while(s<=e){

      if(mountainArr.get(mid)==target){
          return mid;
      }
      else if(mountainArr.get(mid)<target){
          s = mid+1;
      }
      else {
          e = mid-1;
      }
      mid = s+(e-s)/2;
  }     
    return -1;
}    

int bsearchr(int s, int e, MountainArray & mountainArr, int target){
 int mid = s+(e-s)/2;   
  while(s<=e){
      
      if(mountainArr.get(mid)==target){
          return mid;
      }
      else if(mountainArr.get(mid)>target){
          s=mid+1;
      }
      else {
          e=mid-1;
      }
      mid=s+(e-s)/2;
  }     
    return -1;
}
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
    int s = 0, e = n-1 ;
    int mid = s+(e-s)/2;
    int peak ;
    while(s<e){
        if(mountainArr.get(mid) < mountainArr.get(mid+1)){
            s = mid+1;

        }   
        else {
            e = mid;
        }
     mid = s+(e-s)/2;
    }
    peak = s;        
    int left = bsearchl(0, peak, mountainArr, target);
    int right = bsearchr(peak+1, n-1, mountainArr, target);
    
     return left>=0? left:right;
    }
};
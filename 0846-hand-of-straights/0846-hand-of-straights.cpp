class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto it: hand)  mp[it]++;
        sort(hand.begin(),hand.end());
        
        for(auto it: hand){
            if(mp[it]==0)   continue;
            for(int j=0;j<groupSize;j++){
                int tmp=it+j;
                if(mp[tmp]==0)  return 0;
                mp[tmp]--;
            }
        }
        return 1;
    }
};
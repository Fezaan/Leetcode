class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(!st.empty()){
                if((st.top()<0 && asteroids[i]>0)|| (st.top()<0 && asteroids[i]<0) || (st.top()>0 && asteroids[i]>0)){
                    st.push(asteroids[i]);
                }
                else{
                    if(abs(asteroids[i])<abs(st.top()));
                    else if(abs(asteroids[i])==abs(st.top()))   st.pop();
                    else{
                        st.pop();
                        i--;
                    }
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int>st;
        for(int bulb:bulbs){
            if(st.find(bulb)!=st.end()){
                st.erase(bulb);
            }
            else
              st.insert(bulb);
           
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
        
    }
};
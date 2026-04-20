class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<tuple<int,int,int>> v;
        
        int n = trips.size();
        
        for(int i = 0; i < n; i++){
            v.push_back({trips[i][1], +1, trips[i][0]}); 
            v.push_back({trips[i][2], -1, trips[i][0]});
        }

        sort(v.begin(), v.end(), [](tuple<int,int,int>& p1, tuple<int,int,int>& p2){
            if(get<0>(p1) == get<0>(p2))
                return get<1>(p1) < get<1>(p2); 
            return get<0>(p1) < get<0>(p2);
        });

        int curr = 0;

        for(auto &e : v){
            int type = get<1>(e);
            int passengers = get<2>(e);

            curr += type * passengers;

            if(curr > capacity)
                return false;
        }

        return true;
    }
};
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long day = 0;
        for(auto &task : tasks) {
            day++;
            if(mp.count(task) && day - mp[task] <= space) {
                day = mp[task] + space + 1;
            }
            mp[task] = day;
        }
        return day;
    }
};
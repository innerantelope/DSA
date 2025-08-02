#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]++;

        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;
        }

        unordered_map<int, int> count1, count2;
        for (int x : basket1) count1[x]++;
        for (int x : basket2) count2[x]++;

        vector<int> extra1, extra2;

        for (auto& [fruit, _] : freq) {
            int diff = count1[fruit] - count2[fruit];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; i++) extra1.push_back(fruit);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; i++) extra2.push_back(fruit);
            }
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.begin(), extra2.end(), greater<int>());

        int minFruit = min(*min_element(basket1.begin(), basket1.end()), 
                           *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < extra1.size(); i++) {
            cost += min(2 * minFruit, min(extra1[i], extra2[i]));
        }

        return cost;
    }
};

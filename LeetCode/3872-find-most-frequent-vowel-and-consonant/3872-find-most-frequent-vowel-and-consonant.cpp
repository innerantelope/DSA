class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;     
        unordered_map<char,int> cons;  

        for (char c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                mp[c]++;
            } else {
                cons[c]++;
            }
        }

        int maxVowel = 0, maxCons = 0;

        for (auto &p : mp) {
            maxVowel = max(maxVowel, p.second);
        }
        for (auto &p : cons) {
            maxCons = max(maxCons, p.second);
        }

        return maxVowel + maxCons;
    }
};

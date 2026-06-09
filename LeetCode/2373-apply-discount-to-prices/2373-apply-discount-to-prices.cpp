class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> v;
        string w;
        stringstream ss(sentence);
        while (ss >> w) v.push_back(w);
        for (string &s : v) {
            if (s[0] != '$' || s.size() == 1) continue;
            bool ok = true;
            for (int i = 1; i < s.size(); i++) {
                if (!isdigit(s[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                long long price = stoll(s.substr(1));
                double np = price * (100 - discount) / 100.0;
                stringstream temp;
                temp << fixed << setprecision(2) << np;
                s = "$" + temp.str();
            }
        }
        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
            if (i != v.size() - 1) ans += " ";
        }

        return ans;
    }
};
class Solution {
public:
    int maxDiff(int num) {
        if(num < 10) return 8;
        string s = to_string(num);
        char t = 0;
        for(char c : s){
            if(c != '9'){
                t = c;
                break;
            }
        }
        string a = s;
        if(t){
            for(char &ch : a){
                if(ch == t) ch = '9';
            }
        }
        string b = s;

        if(s[0] != '1'){
            char p = s[0];
            for(char &ch : b){
                if(ch == p) ch = '1';
            }
        } else {
            char p = 0;
            for(int i = 1; i < s.size(); i++){
                if(s[i] != '0' && s[i] != '1'){
                    p = s[i];
                    break;
                }
            }
            if(p){
                for(char &ch : b){
                    if(ch == p) ch = '0';
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
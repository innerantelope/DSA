class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26, 0);

        for(char ch : p){
            freq[ch - 'a']++;
        }

        int left = 0;
        int right = p.size() - 1;

        while(right < s.size()){
            
            vector<int> temp = freq;  
            int count = 0;

            for(int k = left; k <= right; k++){
                if(temp[s[k] - 'a'] > 0){
                    temp[s[k] - 'a']--;
                    count++;
                }
                else break;
            }

            if(count == p.size()) ans.push_back(left);

            left++;
            right++;
        }

        return ans;
    }
};
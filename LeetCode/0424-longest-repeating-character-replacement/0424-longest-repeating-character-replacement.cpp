class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int l=0; int r=0;
        int maxfreq=0;
        int best=0;
        while(r<s.length()){
            freq[s[r]]++;
            maxfreq=max(maxfreq,freq[s[r]]);
            r++;
            if((r-l)-maxfreq>k){
                freq[s[l]]--;
                l++;
            }
            best=max(best,r-l);
           

        }

        return best;
    }
};
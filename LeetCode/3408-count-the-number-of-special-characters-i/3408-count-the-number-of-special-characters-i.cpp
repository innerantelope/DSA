class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st;
        int count=0;
        sort(word.begin(),word.end());
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z') st.insert(word[i]);
            else{
                if(st.find(word[i]-32)!=st.end()){
                    count++;
                    st.erase(word[i]-32);
                }
            }
        }
        return count;
    }
};
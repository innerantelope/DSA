class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]].push_back(i);
        }
        int count=0;
        for(int i=0;i<word.size();i++){
            bool check=true;
            if(word[i]>='A' && word[i]<='Z'){
                if(mp.find(word[i]+32)!=mp.end()){
                     if(mp[word[i]+32].back() < mp[word[i]][0]){
                        count++;
                        mp.erase(word[i]+32); 
                    }
                }
                
            }
        }
        return count;

    }
};
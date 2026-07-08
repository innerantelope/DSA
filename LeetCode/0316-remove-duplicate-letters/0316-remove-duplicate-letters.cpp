class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_map<char,int>mp;
        unordered_map<char,bool>vis;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(char ch:s){
            mp[ch]--;
            if(vis[ch]) continue;
            while(!st.empty() && st.top()>ch && mp[st.top()]>0){
                vis[st.top()]=false;
                st.pop();
            }
            st.push(ch);
            vis[ch]=true;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
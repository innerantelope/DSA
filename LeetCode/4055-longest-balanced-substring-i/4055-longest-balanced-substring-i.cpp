class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int max_l=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mn=INT_MAX;
                int mx=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }
                if(mn==mx)  max_l=max(max_l,j-i+1);
                
            }
          
            
        }

        return max_l;



        
    }
};
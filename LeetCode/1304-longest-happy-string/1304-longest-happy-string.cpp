class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       priority_queue<pair<int,int>>pq;
       if(a>0) pq.push({a,'a'});
       if(b>0) pq.push({b,'b'});
       if(c>0) pq.push({c,'c'});
       string ans;
       while(!pq.empty()){
        auto [r,c]=pq.top();
        pq.pop();
        int n=ans.size();
        if(n>=2 && ans[n-1]==c && ans[n-2]==c){
            if(pq.empty()) break;
            auto[s,p]=pq.top();
            pq.pop();
            ans+=p;
            s--;
            if(s>0) pq.push({s,p});
            pq.push({r,c});
        }
        else{
            ans+=c;
            r--;
            if(r>0) pq.push({r,c});
        }

       }

       return ans;


        
    }
};
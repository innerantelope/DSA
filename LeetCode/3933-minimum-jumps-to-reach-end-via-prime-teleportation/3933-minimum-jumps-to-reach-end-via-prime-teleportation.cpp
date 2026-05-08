class Solution {
public:
    vector<bool>isprime;
    void buildseive(int maxel){
        isprime.resize(maxel+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<=maxel;i++){
            if(isprime[i]){
                for(int j=i*i;j<=maxel;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int maxel=0;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxel=max(maxel,nums[i]);
        }
        buildseive(maxel);
        queue<int>que;
        vector<bool>visited(n,false);
        que.push(0);
        visited[0]=true;
        unordered_set<int>seen;
        int steps=0;
        while(!que.empty()){
            int s=que.size();
            while(s--){
                int i=que.front();
                que.pop();
                if(i==n-1)  return steps;
                if(i-1>=0 && !visited[i-1]){
                    que.push(i-1);
                    visited[i-1]=true;
                }
                if(i+1<=n-1 && !visited[i+1]){
                    que.push(i+1);
                    visited[i+1]=true;
                }
                if(!isprime[nums[i]] || seen.count(nums[i])) continue;
                for(int multiple=nums[i];multiple<=maxel;multiple+=nums[i]){
                    if(!mp.contains(multiple)){
                        continue;
                    }
                    for(int &j:mp[multiple]){
                        if(!visited[j]){
                            que.push(j);
                            visited[j]=true;
                        }
                    }
                }
                seen.insert(nums[i]);



            }
            steps++;
        }

        return steps;


        
    }
};
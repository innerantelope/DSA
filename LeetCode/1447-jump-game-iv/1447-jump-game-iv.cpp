class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int>visited(n,false);
        visited[0]=true;
        queue<int>q;
        q.push(0);
        int steps=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                if(curr==n-1){
                    return steps;
                }
                int left=curr-1;
                int right=curr+1;
                
                if(left>=0 && !visited[left]){
                    q.push(left);
                    visited[left]=true;
                }
                if(right<n && !visited[right]){
                    q.push(right);
                    visited[right]=true;
                }
                for(auto &idx:mp[arr[curr]]){
                    if(!visited[idx]){
                        visited[idx]=true;
                        q.push(idx);

                    }
                }
                mp.erase(arr[curr]);


            }
            steps++;

        }

        return -1;

        
    }
};
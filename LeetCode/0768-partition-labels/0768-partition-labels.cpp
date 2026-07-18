class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int>li(26,0);
      for(int i=0;i<s.size();i++){
        li[s[i]-'a']=i;
      }
      int partitions=0;
      int end=0;
      vector<int>ans;
      for(int i=0;i<s.size();i++){
        partitions++;
        end=max(end,li[s[i]-'a']);
        if(i==end){
            ans.push_back(partitions);
            partitions=0;         

        }
      }
      return ans;
    }
};
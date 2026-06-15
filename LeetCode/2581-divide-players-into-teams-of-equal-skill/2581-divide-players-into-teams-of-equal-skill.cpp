class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int s=1,p=n-2;
        int target=skill[0]+skill[n-1];
        long long prod=skill[0]*skill[n-1];
        for(int i=1;i<n/2;i++){
            if((skill[s]+skill[p])==target){
                prod+=(skill[s]*skill[p]);
                s++;
                p--;
            }
            else return -1;
        }
        return prod;
        
    }
};
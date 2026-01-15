class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hul=1;
        int vul=1;
        int currh = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                currh++;
            }
            else{
               currh=1;
            }
            hul = max(hul,currh);
        }
        int currv =1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                currv++;
            }
            else{
               currv=1;
            }
            vul = max(vul,currv);
        }
        
        int side = min(hul,vul)+1;
        return side*side;
    }
};
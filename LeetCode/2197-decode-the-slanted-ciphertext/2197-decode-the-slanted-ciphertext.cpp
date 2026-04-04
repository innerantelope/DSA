class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        string result="";
        for(int c=0;c<col;c++){
            int r=0,j=c;
            while(r<rows && j<col){
                result+=encodedText[r*col+j];
                r++;
                j++;
            }
        }
        while(!result.empty() && result.back()==' ') result.pop_back();

        return result;
        
    }
};
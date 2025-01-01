class Solution {
public:
    int maxScore(string s) {
        int maxi=0;
        for(int i=0;i<s.size()-1;i++){
            int zero=0;
            int one=0;
            for(int j=0;j<s.size();j++){
                if(j<=i && s[j]=='0') zero++;
                if(j>i && s[j]=='1') one++;
            }
            maxi=max(maxi,zero+one);
        }
        return maxi;
    }
};
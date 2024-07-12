class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s1="";
        string s2="";
        while(start>0){
            s1+=(start&1)?'1':'0';

            start>>=1;
        }
        while(goal>0){
            s2+=(goal&1)?'1':'0';
            goal>>=1;
        }
        while(s1.size()<s2.size()){
            s1+='0';
        }
        while(s2.size()<s1.size()){
            s2+='0';
        }
        int count=0;
        for(size_t i=0;i<s1.size();++i){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        return count;
    }
};
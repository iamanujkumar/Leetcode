class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),i=0;
        string str="";
        while(i<n){
            string t="";
            while(s[i]==' ' && i<n){
                i++;
            }
            while(s[i]!=' ' && i<n){
                t+=s[i];
                i++;
            }
            if(!t.empty()){
                if(!str.empty()){
                    str=t+" "+str;
                }
                else  str=t;
            }
        }
        return str;
    }
};
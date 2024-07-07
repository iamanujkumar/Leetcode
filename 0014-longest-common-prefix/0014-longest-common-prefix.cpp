class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str="";
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            bool flag=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()<i || ch!=strs[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
            else str+=ch;
        }
        return str;
    }
};
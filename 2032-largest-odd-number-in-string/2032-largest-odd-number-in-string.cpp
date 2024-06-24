class Solution {
public:
    string largestOddNumber(string num) {
        for(int j=num.size()-1;j>=0;j--){
            if((num[j]-'0')%2==1){
                return num.substr(0,j+1);
            }
        }
        return "";
    }
};
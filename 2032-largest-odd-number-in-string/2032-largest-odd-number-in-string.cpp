class Solution {
public:
    string largestOddNumber(string num) {
        int j=0;
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]%2!=0){
                j=i;
                break;
            }
        }
        string str="";
        if(j!=0){
            for(int i=0;i<=j;i++){
            str+=num[i];
        }
        }
        else if(num[0]%2!=0){
            str+=num[0];
        }
        return str;
    }
};
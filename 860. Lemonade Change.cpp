class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count1=0;
        int count2=0;
        bool flag=true;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                count1++;
            }
            else if(bills[i]==10){
                
                if(count1<=0){
                    return false;
                }
                
                count1--;
                count2++;
                           
            }
            else if(bills[i]==20){
                if(count1>=1 && count2>=1){
                    count1--;
                    count2--;
                }
                else if(count1>2){
                    count1-=3;
                }
                else return false;
            }
        }
        return true;
    }
};
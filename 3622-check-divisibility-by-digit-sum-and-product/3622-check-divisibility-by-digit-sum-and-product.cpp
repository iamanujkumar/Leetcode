class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int N=n;
        while(N!=0){
            int val=N%10;
            sum+=val;
            prod*=val;
            N=N/10;
        }
        sum=sum+prod;
        if(n%sum==0){
            return true;
        }
        return false;
    }
};
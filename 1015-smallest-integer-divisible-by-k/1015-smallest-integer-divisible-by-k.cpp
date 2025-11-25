class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long count=1;
        for(int i=0;i<=k;i++){
            if(count%k==0){
                return i+1;
            } 
            count=(count*10+1)%k;
        }
        return -1;
    }
};
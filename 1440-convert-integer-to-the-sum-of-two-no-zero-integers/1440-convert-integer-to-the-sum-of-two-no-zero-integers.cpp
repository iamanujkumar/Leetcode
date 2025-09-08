class Solution {
public:
    bool haszero(int x){
        while(x>0){
            if(x%10==0) return true;
            x/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int j = n-i;
            if(!haszero(i) && !haszero(j)){
                return{i,j};
            }
        }
        return {};
    }
};
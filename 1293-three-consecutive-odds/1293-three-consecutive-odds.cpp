class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ctn=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                ctn++;
                if(ctn==3){
                    return true;
                }
            }
            else{
                ctn=0;
            }
        }
        return false;
    }
};
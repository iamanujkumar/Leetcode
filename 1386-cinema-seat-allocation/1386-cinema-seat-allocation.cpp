class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int ans = n*2;
        for(int i=0;i<reservedSeats.size();){
            int row = reservedSeats[i][0];

            bool left = true;
            bool middle = true;
            bool right = true;

            int j=i;
            while(j<reservedSeats.size() && reservedSeats[j][0] == row){
                int seat = reservedSeats[j][1];
                if(seat >=2 && seat<=5){
                    left = false;
                }
                if(seat>=4 && seat<=7){
                    middle = false;
                }
                if(seat>=6 && seat<=9){
                    right = false;
                }
                j++;
            }
            int val = 0;
            if(left && right){
                val=2;
            }
            else if(left | middle | right){
                val=1;
            }
            ans -=2;
            ans+=val;
            i=j;
        }
        return ans;
    }
};
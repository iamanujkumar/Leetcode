class Solution {
public:
    int countCollisions(string directions) {
        int i=0,j=directions.size()-1;
        int count=0;
        while(i<=directions.size()-1 && directions[i]=='L') i++;
        while(j>=0 && directions[j]=='R') j--;
        while(i<=j){
            if(directions[i]!='S'){
                count++;
            }
            i++;
        }
        return count;
    }
};
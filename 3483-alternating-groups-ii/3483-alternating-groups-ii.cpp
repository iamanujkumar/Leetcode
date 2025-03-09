class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int cnt=0;
        int l=0;
        int lmt=n+k-1;
        while(l<n){
            int r=l+1;
            while(r<lmt and colors[(r-1)%n]!=colors[r%n])
                r++;
            if(r-l >= k)
                cnt += (r-l) - k + 1;
            l=r;
        }
        return cnt;
    }
};
class Solution {
public:
    long long minimumSteps(string s) {
         int n=s.length();
        int lst=0;
        long ans=0;
        for(int curr=0;curr<n;curr++){
            if(s[curr] == '0'){
               ans+=(curr-lst);
                lst++;
            }
        }
        return ans;
    }
};
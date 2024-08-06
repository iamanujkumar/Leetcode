class Solution {
public:
    int minimumPushes(string word) {
        vector<int>fq(26,0);
        for(auto ch:word){
            fq[ch-'a']++;
        }
        sort(fq.begin(),fq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=fq[i]*((i/8)+1);


        }
        return ans;
    }
};
class Solution {
public:
    int minChanges(string s) {
        vector<int> vec;
        int n=s.size();
        int i=1;
        int start=0;
        int cnt=0;
        while(i<n){
            while(i<n and s[i]==s[i-1])
                i++;
            
            if((i-start)&1)
                vec.push_back(cnt);
            cnt++;
            start=i;
            i++;
        }
        if((i-start)&1)
            vec.push_back(cnt);
        int minChanges=0;
        for(int pos=1;pos<vec.size();pos+=2)
            minChanges += vec[pos]-vec[pos-1];
        return minChanges;
    }
};
class Solution {
    #define ll long long
    ll findMaxPoints(vector<vector<int>>& questions,int pos,vector<ll>& mem){
        if(pos >= questions.size())
            return 0;
        if(mem[pos]!=-1)
            return mem[pos];
        ll exc = findMaxPoints(questions,pos+1,mem);
        ll inc = questions[pos][0] + findMaxPoints(questions,pos+questions[pos][1]+1,mem);
        return mem[pos] = max(exc,inc);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> mem(n,-1);
        return findMaxPoints(questions,0,mem);
    }
};
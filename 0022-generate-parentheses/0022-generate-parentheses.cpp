class Solution {
public:

void fun(vector<string>&ans, int n, int o,int c, string s){
    if(o==n && c==n) {
        ans.push_back(s);
        return;
    }
    if(o<n){
        fun(ans,n,o+1,c,s+"(");
    }
    if(c<o){
        fun(ans,n,o,c+1,s+")");
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int o=0,c=0;
        fun(ans,n,o,c,"");
        return ans;
    }
};
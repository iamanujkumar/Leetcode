class Solution {
public:
vector<int>gen(int row){
    int ans=1;
    vector<int>ansR;
    ansR.push_back(ans);
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/i;
        ansR.push_back(ans);
    }
    return ansR;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(gen(i));
        }
        return ans;
    }
};
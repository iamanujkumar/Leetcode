class Solution {
public:
    int hist(vector<int>&pref){
        int n=pref.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<=n;i++){
            int curr = (i==n?0:pref[i]);
            while(!st.empty() && pref[st.top()]>curr){
                int h=pref[st.top()];
                st.pop();
                int left = st.empty()?0:st.top()+1;
                int right = i-1;
                int width = right-left+1;
                maxi = max(maxi,h*width);
            }
            if(i<n){
                st.push(i);
            }
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>pref(m,vector<int>(n));
        int maxArea=0;
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                pref[i][j]=sum;
            }
        }
        for(int i=0;i<m;i++){
            maxArea = max(maxArea, hist(pref[i]));
        }
        return maxArea;
    }
};
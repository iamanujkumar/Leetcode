class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int top=m,left=n,bottom=-1,right=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    top=min(top,i);
                    bottom=max(bottom,i);
                    left=min(left,j);
                    right=max(right,j);
                }
            }
        }
        if(bottom==-1) return 0;
        return (bottom-top+1)*(right-left+1);
    }
};
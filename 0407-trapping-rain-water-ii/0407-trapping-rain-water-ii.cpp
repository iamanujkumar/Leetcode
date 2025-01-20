class Solution {
    #define pip pair<int,pair<int,int>>

    bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 or n<3)  //Need minimum 3*3 matrix to hold water
            return 0;

        //Step-1: Push all boundary elements as START points
        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    minheap.push(make_pair(heightMap[i][j],make_pair(i,j)));
                    visited[i][j]=true;
                }
            }
        }

        //Step-2: Apply BFS similar to level-order traversal
        int level=0;
        int ans = 0;
        vector<int> dir = {-1,0,1,0,-1};//URDL 4-dir calls
        
        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();

            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level,height);
            
            //4-directional traversal
            for(int i=0;i<4;++i){
                int nw = x + dir[i];
                int nwy = y + dir[i+1];
                if(isValid(nw,nwy,m,n) and !visited[nw][nwy]){
                    visited[nw][nwy] = true;
                    minheap.push(make_pair(heightMap[nw][nwy],make_pair(nw,nwy)));
                    if(heightMap[nw][nwy] < level)
                        ans += level - heightMap[nw][nwy];
                }
            }
        }
        return ans;
    }
};